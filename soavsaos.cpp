#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define N 1000000

struct pointlist3D {
    float x[N];
    float y[N];
    float z[N];
};

struct pointlist3D pointsSOA;
/*
float get_point_xSOA(int i) 
{ 
	return pointsSOA.x[i]; 
}
*/

struct point3D {
    float x;
    float y;
    float z;
};
struct point3D pointsAOS[N];
/*
float get_point_xAOS(int i) 
{ 
	return pointsAOS[i].x; 
}
*/
int main()
{
	int x,y,z;
	float percent;
	for(int i=0; i<N ; i++)
	{
		pointsSOA.x[i] = i;
		pointsAOS[i].x = i;
	}
	printf("Accesing only coordinate x ");

	auto start = high_resolution_clock::now();
	
	for(int i=0; i<N ; i++)
		x = pointsAOS[i].x;

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\nTime taken for AOS : "<<duration.count();

	auto start2 = high_resolution_clock::now();

	for(int i=0; i<N ; i++)
		x = pointsSOA.x[i];

	auto stop2 = high_resolution_clock::now();

	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	cout << "\nTime taken for SOA : "<<duration2.count();

	cout<<"\n";
	if(duration2 < duration)
	{
		cout<<"\nSOA is better when accesing only point x\n";
	}
	else
		cout<<"\nAOS is better when accesing only point x\n";	
	

	printf("\nAccesing all coordinates  ");

	auto start3 = high_resolution_clock::now();
	
	for(int i=0; i<N ; i++)
	{
		x = pointsAOS[i].x;
		y = pointsAOS[i].y;
		z = pointsAOS[i].z;
	}

	auto stop3 = high_resolution_clock::now();

	auto duration3 = duration_cast<microseconds>(stop3 - start3);
	cout << "\nTime taken for AOS : "<<duration3.count();


	auto start4 = high_resolution_clock::now();

	for(int i=0; i<N ; i++)
	{
		x = pointsSOA.x[i];
		y = pointsSOA.y[i];
		z = pointsSOA.z[i];
	}

	auto stop4 = high_resolution_clock::now();

	auto duration4 = duration_cast<microseconds>(stop4 - start4);
	cout << "\nTime taken for SOA : "<<duration4.count();

	cout<<"\n";

	cout<<"\n";
	if(duration4 < duration3)
	{
		cout<<"\nSOA is better when accesing all coordinates\n";
	}
	else
		cout<<"\nAOS is better when accesing all coordinates\n";	

}
