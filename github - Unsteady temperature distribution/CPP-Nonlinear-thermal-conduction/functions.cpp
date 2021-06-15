#include <iostream>
#include <fstream>
#include <math.h>
#include "functions.h"


using namespace std;

void twodarrays::redistribution(int nx, int ny, arrays x_axis, arrays y_axis)
{
	for (int i = 0; i < nx; i++)
		for (int j = 0; j < ny; j++) {
			{
				if (((x_axis.data[i] - 0.5) * (x_axis.data[i] - 0.5)) +
					((y_axis.data[j] - 0.5) * (y_axis.data[j] - 0.5)) < 0.2)
				{
					arr[i][j] = 40;
				}
			} 
		}
}

void twodarrays:: gauss_jacobi_implicit( int nx, int ny, double k1, double k2, double tolerance, double totime, double dtime)
{
	int jacobi = 0;
	for (double t = 0; t < totime; t = t + dtime)
	{
		int flag=0;
		int k = 0;
		do
		{ ++jacobi;
		// limiting non -convergent iterations - exit clause
		
			for (int i = 1; i < nx-1; i++)
			{
				for (int j = 1; j < ny-1 ; j++)
				{
					 flag = 0;
					double tprev = arr[i][j];

					double ttop = arr[i - 1][j];
					double tbottom = arr[i + 1][j];
					double tright = arr[i][j + 1];
					double tleft = arr[i][j - 1];

					

					double denom = 1. + (2. * k1 * k1) +( 2. * k2 * k2);

					double tnow = (tprev + (k1 * (tleft + tright)) + (k2 * (ttop + tbottom))) / (denom);

					double error = abs(tnow - tprev);

					if (error > tolerance)
					{
						flag++;
						k = k+1;
						if (k > 100)
						{ 
							cout << "\n";
							cout << " Non convergence reached limit k= " << k<<"\n"; 
							for (int i = 0; i < nx; i++)
							{
								for (int j = 0; j < ny; j++)
								{
									cout << arr[i][j] << "\t";
								}
								cout << "\n";
							}
							exit(1);
						}
						cout << "Not - Convergerd \t" << "i=" << i << "j=" << j << "jacobi =" << jacobi << "time=" << t <<"error="<<error<< "\n";
					}
					else {

						cout << "Convergerd \t" << "i =" << i << "j=" << j << "jacobi =" << jacobi<< "time=" << t << "\n";
					}
					// dynamic printing of temperature at fixed intervals

					arr[i][j] = tnow; 
					//cout << "flag" << flag << "\t"<< "time"<< t<< "\n";
					//cout << "error" << error<<"\n";
					//cout << "i =" << i << "j=" << j << "temp = " << temperature.arr[i][j] << "\t";
				}
			}
		} while (flag > 0);
		if ((abs(t - double(0)) < 0.01)  || (abs(t - double(5)) < 0.01) 
			       || (abs(t - double(20)) < 0.01)
		         	      || (abs(t - double(50)) < 0.01)
			                        || (abs(t - double(7200)) < 0.01))
		{
			printout( nx,  ny, t);

		}
	}
	//cout << "jacobi" << jacobi<< "\t";
}

void twodarrays::printout(int nx, int ny, double t) {

	 
		ofstream outdata; // outdata is like cin
		char buffer[30]; // make sure it's big enough
		snprintf(buffer, sizeof(buffer), "temperature_at_%i_sec.txt", int(t));
		outdata.open(buffer);

		if (!outdata) { // file couldn't be opened
			cerr << "Error: file could not be opened" << endl;
			exit(1);
		}
		outdata << "time = " << t <<"\n";
		for (int i = 0; i < nx; i++)
		{

			for (int j = 0; j < ny; j++)
			{
				outdata << arr[i][j] << "\t";
			}
			outdata << "\n";
		}
		outdata.close();
	
	
}

void arrays::print(int nx, int ny)
{

	ofstream xdata; // outdata is like cin
	xdata.open("xaxis.dat");
	
	if (!xdata) { // file couldn't be opened
		cerr << "Error: x axis file could not be opened" << endl;
		exit(1);
	}

		for (int i = 0; i < nx; i++)
		{
			xdata << data[i] << "\t";
		}
		 xdata.close();

		 ofstream ydata;
		 // opens the file
		 ydata.open("yaxis.dat");

		 if (!ydata) { // file couldn't be opened
			 cerr << "Error: y axis file could not be opened" << endl;
			 exit(1);
		 }

		for (int j = 0; j < ny; j++)
		{
			ydata << data[j] << "\t";
		}
	ydata.close();

}

