#include <stdlib.h>     
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <list>
#include <string>
#include <ctime>
using namespace std;

//!	 Graph class 
class graph {
private: 
		//! The matrix - count adjacency matrix
		vector<vector<bool>> matrix;
		//! The size - graph's size
		int size;
		//! The chromatic_number - graph's chromatic number
		int chromatic_number;
		//! The color_table - structure for storing vertices by color
		vector< list <int> > color_table;
		//! The color_array - array of color
		vector<int> color_array;
public:
	graph();
	~graph();
	/*!
	\brief Input graph
	\param[in] fin - object of class ifsream (input stream class to operate on files)
	*/
	void input(ifstream &fin);
	/*!
		\brief Output graph
		\param[in] fout - object of class îfsream (output stream class to operate on files)
	*/
	void output(ofstream &fout);
	/*!
		\brief Greedy algorithm of graph coloring
		\return color_table - format to storage of the painted graph
	*/
	vector< list <int> > greedy();
	/*!
		\brief The function of sorting graph nodes by their powers in descending order
		\return sort_array - sorted array
	*/
	vector<int> sort();
	/*!
		\brief Brute-force graph coloring algorithm
		\param[in] node - the number of the node from which we start coloring the graph
		\param[in] max_color - the quantity of colors that we will try to color the graph
		\return 1 if the graph is colored, 0 if the graph is not colored
	*/
	bool brute_force(int node, int max_color);
};



