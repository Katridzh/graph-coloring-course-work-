#include "Graph.h"

graph::graph() {
	size = 0;
	chromatic_number = size;
	matrix.resize(size);
	color_table.resize(size);
	color_array.resize(size);
}


graph::~graph() {
	matrix.clear();
	color_table.clear();
	color_array.clear();
}


void graph::input(ifstream &fin) {
	fin >> size;
	matrix.resize(size, std::vector<bool>(size, 0));
	bool r;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			fin >> r;
			matrix[i][j] = r;
		}
	}
	chromatic_number = size;
	color_table.resize(size + 1);
	color_array.resize(size);
	for (int i = 0; i < size; i++) {
		color_array[i] = 0;
	}
	fin.close();
}


void graph::output(ofstream &fout) {
	for (int i = 1; i <= chromatic_number; i++)
	{
		cout << "[" << i << "]:  ";
		for (list< int>::const_iterator it = color_table[i].begin(); it != color_table[i].end(); it++)
		{
			cout << *it << ' ';
		}
		cout << '\n';
	}
	cout << "Enter " << chromatic_number << " color names:\n";
	vector< string > names(chromatic_number + 1);
	for (int i = 1; i <= chromatic_number; i++)
	{
		cin >> names[i];
	}
	fout << "graph{\n";
	for (int i = 1; i <= chromatic_number; i++)
	{
		fout << "{\n node[shape = circle; style = filled; fillcolor = " << names[i] << "];\n ";
		for (list< int>::const_iterator it = color_table[i].begin(); it != color_table[i].end(); it++)
		{
			fout << *it << "; ";
		}
		fout << "\n}\n";
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			if (matrix[i][j] == 1)
				fout << i + 1 << "--" << j + 1 << "\n";
		}
	}
	fout << "}\n";
}


bool graph::brute_force(int node, int max_color) {
	bool check = 0;
	int count = 0;
	if (node == size)
	{
		chromatic_number = max_color;
		return 1;
	}
	else {
		for (int i = 1; i <= max_color; i++) {
			for (list< int>::iterator it = color_table[i].begin(); it != color_table[i].end(); ++it) {
				if (matrix[*it - 1][node] == 1)
				{
					++count;
				}
			}
			if (count == 0) {
				color_table[i].push_front(node + 1);
				color_array[node] = i;
				check = brute_force(node + 1, max_color);
				if (check == true)
					goto stop;
				else {
					color_table[i].erase(color_table[i].begin());
					color_array[node] = 0;
				}
			}
			count = 0;
		}
	}
	if (node == 0) {
		color_table.clear();
		color_table.resize(size + 1);
		color_array.clear();
		color_array.resize(size);
		return 0;
	}
stop:;
}

vector<int> graph::sort() {
	std::vector<int> l(size, 0);
	int count;
	for (int i = 0; i < size; ++i)
	{
		count = 0;
		for (int j = 0; j < size; ++j)
		{
			if (matrix[i][j] == 1)
				count++;
		}
		l[i] = count;
	}
	std::vector<int> k(size);
	count = 0;
	int tmp;
	for (int i = 0; i < size; i++) {
		k[count] = i + 1;
		tmp = l[i];
		for (int j = 0; j < size; j++) {
			if (tmp < l[j]) {
				tmp = l[j];
				k[count] = j + 1;
			}
		}
		l[k[count] - 1] = -1;
		count++;
	}
	return(k);
}


vector< list <int> > graph::greedy() {
	vector<int> k = this->sort();
	vector<bool> visited(size, 0);
	int color = 1;
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (i == 0 || visited[k[i] - 1] == 0) {
			color_table[color].push_front(k[i]);
			visited[k[i] - 1] = 1;
			for (int j = i + 1; j < size; j++) {
				if (visited[k[j] - 1] == 0) {
					for (list< int>::iterator it = color_table[color].begin(); it != color_table[color].end(); ++it) {
						if (matrix[*it - 1][k[j] - 1] == 1)
						{
							++count;
						}
					}
					if (count == 0) {
						color_table[color].push_front(k[j]);
						visited[k[j] - 1] = 1;
					}
					count = 0;
				}
			}
			color++;
		}
	}
	chromatic_number = color - 1;
	color_table.resize(color);
	return (color_table);
}