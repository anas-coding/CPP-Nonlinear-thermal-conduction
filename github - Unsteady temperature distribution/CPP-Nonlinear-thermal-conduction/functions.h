#include <iostream>
using namespace std;

#pragma once
//#include "functions.cpp"

// creating and storing the values of co-ordinate axeses  
class arrays
{
public:
	double* data;
	int size;
public:
	arrays(int size, int length)
	{
		data = new double[size];
		this->size = size;
		// intializing to axis nodal values
		for (int i = 0; i < size; ++i)
			data[i] =  i* (length/double( size-1));
	}
	

	// for printing x-axis and y-axis values 
	void print(int nx, int ny);

//	~arrays() { delete[] data; };
};

// temperature array to store temperatre values at particular node points viz., (x,y)
class twodarrays
{ 
public:
	double** arr;
	double* rows;
	
public:
	// constructor
	 twodarrays(int rows, int cols, double lw, double tw, double rw, double bw) 
	{
		 arr = new double* [rows];
		for (int i = 0; i < rows; ++i)
			arr[i] = new double[rows];
		// intialising temperatures to '0'

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = 20;
			}
		}

		// updating  left wall temperature
		for (int i = 0; i < rows; ++i)
			arr[i][0] = lw;

		// updating top wall temperature
		for (int j = 0; j < cols; ++j)
			arr[0][j] = tw;

		// updating right wall temperature
		for (int i = 0; i < rows; ++i)
			arr[i][(cols - 1)] = rw;

		// updating bottom wall temperature
		for (int j = 0; j < cols; ++j)
			arr[(rows - 1)][j] = bw;

		// correcting corner temperatures 
		// not needed as all wall temperatures are same
		// top left corner
		//arr[0][0] = (lw + tw) / 2.;
		// top right corner
	//	arr[0][cols - 1] = (tw + rw) / 2.;
		// bottom right corner
		//arr[rows - 1][cols - 1] = (rw + bw) / 2.;
		// bottom left corner
		//arr[rows - 1][0] = (lw + bw) / 2.;
	}

		
	

	// temperature re distribution inside the domain
	void redistribution(int nx, int ny, arrays x_axis,arrays y_axis);

	// gauss jacobi iterations

	void gauss_jacobi_implicit( int nx, int ny, double k1, double k2, double tolerance, double totime, double dtime);
	
	

	// printout for plotting
    void printout( int nx, int ny,double t);

	// destructor

	~twodarrays() { delete[] arr; }
};


