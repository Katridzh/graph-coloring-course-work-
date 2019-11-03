#include "Graph.h"

/*!
\brief Main function
\param[in] file.exe, file.txt where the information about graph is,file.gv where the result will be written, algorithm number(0 -- brute-force, 1 -- greedy algorithm)
\throw "ERROR(not arguments)" If the user does not enter enough arguments
\throw "FILE NOT FOUND" If the user enters an incorrect(nonexistent) name of the file containing the information about graph 
*/

int main(int argc, char* argv[])
{
	try {
		if (argc < 3) {
			throw "ERROR(not arguments)\n";
			return EXIT_FAILURE;
		}
	 else {
			ifstream fin(argv[1]);
			if (!fin.is_open())
				throw "FILE NOT FOUND\n";
			ofstream fout(argv[2]);
			graph new_graph;
			new_graph.input(fin);
			char alg_num= *argv[3];
			if (alg_num == '0') {
				unsigned int start_time = clock();
				bool done = false;
				int max_color = 1;
				while (done != true) {
					done = new_graph.brute_force(0, max_color);
					max_color++;
				}
				unsigned int end_time = clock();
				unsigned int search_time = end_time - start_time;
				cout << "runtime = " << search_time<<" ms"<< endl;
			}
			if (alg_num == '1') {
				unsigned int start_time = clock();
				new_graph.greedy();
				unsigned int end_time = clock();
				unsigned int search_time = end_time - start_time;
				cout << "runtime = " << search_time << " ms" << endl;
			}
			new_graph.output(fout);
		}
	}
	catch (char *str) {
		cout << str << endl;
	}
	return 0; 
}
