/*  tcspl.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */

#include "cspl.h"

#define MD 8
/* number of splines = interpolation points - 1 = MD - 1*/

/* x values */
double x[MD] = {0.0, 0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4};
/* y values */
double y[MD] = {0.0, 1.5, 1.8, 0.5, -1.0, -1.2, -0.3, 0.5};
/*output array of MD second derivatives*/
double p[MD];

int main(int argv, char **argc)
{
    cspl(x, y, p, MD - 1, 0);
    for (int j = 0; j < MD; ++j)
        printf(" %d x=%10.6f y=%10.6f Y=%10.6f z=%12.8f \n", j, x[j], y[j], csfit(x[j], x, y, p, MD - 1), p[j]);
    return 0;
}
/*
cspl
     Compute a cubic or tensioned spline fit to an open curve.

     cspl(double x[],double y[],double z[],int m,double tn)
        x = array containing m+1 x-coordinates of the curve
        y = array containing m+1 y-coordinates of the curve
        z = output array of m+1 second derivatives
             ( the boundary condition assumes z[0]=z[m]=0. )
        m = number of intervals (m+1 input points)
        tn = tension parameter, with:
              tn = 0. -> cubic spline
              tn > 0. -> spline in tension


csfit
     Evaluate a cubic spline curve at any interior point.

     double csfit(double w,double x[],double y[],double z[],int m)
        w = value of the independent variable
        x,y,z = m+1 dimensional arrays define a cubic spline
        m = number of intervals
      return value: cs(w) = cubic spline interpolation if  x[0]<=w<=x[m]
                            ( 0.0 is returned for w<x[0] or w>x[m] )

        This function is used to evaluate splines computed with tn=0.0.
*/