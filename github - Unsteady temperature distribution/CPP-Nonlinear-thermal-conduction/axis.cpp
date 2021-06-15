#include "classes.h"
 axispoints::axispoints(int numberofpoints) {
	gridpoints = new int[numberofpoints];
	this->numberofpoints = numberofpoints;
}
 axispoints::~axispoints() { delete[]  gridpoints; }
