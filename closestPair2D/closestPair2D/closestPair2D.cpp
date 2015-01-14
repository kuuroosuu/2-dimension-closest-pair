#include "closestPair2D.h"
#include <cmath>
#include <algorithm>

float dist(point p1, point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

struct xComparisor {
	bool operator () (point p1, point p2) { return p1.x<p2.x;}
};
struct yComparisor {
	bool operator () (point p1, point p2) { return p1.y<p2.y;}
};

vector<point> psortx(vector<point> points)
{
	sort(points.begin(), points.end(), xComparisor());
	return points;
}
vector<point> psorty(vector<point> points)
{
	sort(points.begin(), points.end(), yComparisor());
	return points;
}

float closestPair2D::closestDist(vector<point> points)
{
	if(points.size() == 2)
		return dist(points[0], points[1]);
	if(points.size() == 1)
		return -1;

	points = psortx(points);
	vector<point> lpoints;
	vector<point> rpoints;
	for(int i = 0;i < points.size()/2;i++)
		lpoints.push_back(point(points[i].x,points[i].y));
	for(int i = points.size()/2;i < points.size();i++)
		rpoints.push_back(point(points[i].x,points[i].y));
	float ldist = closestDist(lpoints);
	float rdist = closestDist(rpoints);
	float d;
	if(ldist==-1)
		d = rdist;
	else if(rdist==-1)
		d = ldist;
	else
		d = min(ldist, rdist);

	vector<point> lpointsINd;
	vector<point> rpointsINd;
	for(int i = 0;i < lpoints.size()-1;i++)
		if(lpoints[lpoints.size()-1].x-lpoints[i].x < d)
			lpointsINd.push_back(point(lpoints[i].x, lpoints[i].y));
	for(int i = 0;i < rpoints.size()-1;i++)
		if(rpoints[rpoints.size()-1].x-rpoints[i].x < d)
			rpointsINd.push_back(point(rpoints[i].x, rpoints[i].y));
	lpointsINd.push_back(point(lpoints[lpoints.size()-1].x, lpoints[lpoints.size()-1].y));
	rpointsINd.push_back(point(rpoints[rpoints.size()-1].x, rpoints[rpoints.size()-1].y));
	lpointsINd = psorty(lpointsINd);
	rpointsINd = psorty(rpointsINd);
	int rPointer = 0;
	for(int i = 0;i < lpointsINd.size();i++)
	{
		if(rPointer<6)
			rPointer = 0;
		else
			rPointer -= 6;
		while(1)
		{
			if(rPointer>=rpointsINd.size() ||
				abs(lpointsINd[i].y-rpointsINd[rPointer].y)>d)
				break;
			float _d = dist(lpointsINd[i],rpointsINd[rPointer]);
			if(_d<d)
				d = _d;
			rPointer++;
		}
	}
	return d;
}

