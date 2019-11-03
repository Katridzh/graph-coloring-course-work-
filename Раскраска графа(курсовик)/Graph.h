#include <stdlib.h>     
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <list>
#include <string>
#include <ctime>
using namespace std;
/**
/brief Graph class 

\file
\brief Header file with class description

This class that describes a graph, its fields and methods.
*/

class graph {
private: 
		vector<vector<bool>> matrix;///<adjacency matrix
		int size;///<matrix size
		int chromatic_number;///<the chromatic number of a graph
		vector< list <int> > color_table;///<table for storing colored vertices
		vector<int> color_array;///<array of colors
public:
	/*!
	\brief The constructor of the graph
	*/	
	graph();
	/*!
	\brief The destructor of the graph
	*/
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
	vector<int> sort() const;
	/*!
		\brief Brute-force graph coloring algorithm
		\param[in] node - the number of the node from which we start coloring the graph
		\param[in] max_color - the quantity of colors that we will try to color the graph
		\return 1 if the graph is colored, 0 if the graph is not colored
	*/
	bool brute_force(const int & node, const int & max_color);
};



