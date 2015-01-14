#include "closestPair2D.h"
#include <iostream>

using namespace std;

int main()
{
	vector<point> points;
	/*points.push_back(point(0,0));
	points.push_back(point(1,0));
	points.push_back(point(0,1));
	points.push_back(point(1,1));*/

	points.push_back(point(29,2));
	points.push_back(point(0,19));
	points.push_back(point(4,94));
	points.push_back(point(51,45));
	points.push_back(point(80,47));
	points.push_back(point(44,34));
	points.push_back(point(28,80));
	points.push_back(point(14,54));
	points.push_back(point(43,18));
	points.push_back(point(71,44));
	points.push_back(point(86,6));
	points.push_back(point(33,97));
	points.push_back(point(49,94));
	points.push_back(point(23,37));
	points.push_back(point(55,90));
	points.push_back(point(19,96));
	points.push_back(point(97,57));
	points.push_back(point(93,43));
	points.push_back(point(84,79));
	points.push_back(point(23,81));

	cout << closestPair2D::closestDist(points);
	system("pause");
	return 0;
}