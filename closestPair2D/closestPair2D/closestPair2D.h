#include <iostream>
#include <vector>

using namespace std;

struct point
{
	float x, y;
	point(float _x, float _y) { x = _x; y = _y;}
};

class closestPair2D {
public:
	static float closestDist(vector<point> points);

private:
	
};
