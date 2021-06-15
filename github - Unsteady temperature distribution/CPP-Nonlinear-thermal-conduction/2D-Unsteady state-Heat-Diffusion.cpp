// 2D-Unsteady state-Heat-Diffusion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <math.h>
#include "functions.h"

using namespace std;

int main()
{
   cout << "Hello Spiderman!\n";
    //----------
    // defining square domain
    int L = 1;
    int nx, ny,nxx, nyy;
    // input nx grids
    // cout << "Input your number of descrete elements for x- axis " << "\n";
    //cin >> nxx;
    nxx = 5;

    //cout << "Input your number of descrete elements for y- axis " << "\n";
    //cin >> nyy;
    nyy = 5;
    // calculating x-axis and y-axis co-ordinates

    /// nx, ny is the number cordinates in x-,y-, axis.
    nx = nxx + 1;
    ny = nyy + 1;
    arrays x_axis(nx,L);
    arrays y_axis(ny,L);
    x_axis.print(nx, ny);
   // cout << x_axis.data[0] << "\t" << x_axis.data[1] << "\t" << x_axis.data[2] << "\n";
   // cout << y_axis.data[0] << "\t" << y_axis.data[1] << "\t" << y_axis.data[2] << "\t";



    // Temperature array delaration and initialisation

    // applying boundary conditions
    double left_wall_temp, right_wall_temp, bottom_wall_temp, top_wall_temp;
    //cout << "Input your left wall temperature" << "\n";
   // cin >> left_wall_temp;
   // cout << "Input your top wall temperature" << "\n";
    //cin >> top_wall_temp;
   // cout << "Input your right wall temperature" << "\n";
   // cin >> right_wall_temp;
  //  cout << "Input your bottom wall temperature" << "\n";
   // cin >> bottom_wall_temp;
    left_wall_temp = 20;
    right_wall_temp = 20;
    bottom_wall_temp = 20;
    top_wall_temp = 20;

    twodarrays temperature(nx, ny, left_wall_temp, top_wall_temp, right_wall_temp, bottom_wall_temp);

    temperature.redistribution(nx, ny, x_axis, y_axis);
    /*
    // print test
  for (int i = 0; i < nx; i++)
  {
      for (int j = 0; j < ny; j++)
      {
          cout << temperature.arr[i][j] << "\t";
      }

  }

  */

 // cout << "\n";
   // define dx, dy

  double dx = ( L / double(nxx));
  double dy = (L / double(nyy));

  // define dt

  double totime, dtime;

 // cout << "Input total time of this simulation" << "\n";
  //cin >> totime;

  totime = 1;

  //cout << "Input time increment(dt) for this simulation" << "\n";
  //cin >> dtime;

  dtime = 0.01;

  // define

  double alpha;

 // cout << "Input Coefficient of thermal diffusivity for this simulation" << "\n";
  //cin >> alpha;

  alpha = -1e-6;


  // gauss - jacobi explicit iteration scheme

   // define tolerance

  double tolerance = 1e-4;

  double k1 = (alpha * dtime) /  (dx*dx);
  double k2 = (alpha * dtime) / ( dy*dy);

  //  gauss - jacobi implicit

  temperature.gauss_jacobi_implicit(nx, ny, k1, k2, tolerance, totime, dtime);

  // print test
 /*
  for (int i = 0; i < nx; i++)
  {
      for (int j = 0; j < ny; j++)
      {
          cout << temperature.arr[i][j] << "\t";
      }

  }
  */
  //temperature.printout(nx,ny);

   cout << " \n Hi Spidey !! Code compiled successfully ! \n";


  //return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

