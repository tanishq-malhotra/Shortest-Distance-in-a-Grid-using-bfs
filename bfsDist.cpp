#include<bits/stdc++.h>
using namespace std;
//short distance class created to store the row and col of the grid
class sh
{
public:
	int x,y,dist;
	sh(){}
	//parameterised constructor to set the values to desired
	sh(int i,int j,int d)
	{
		x = i; y = j; dist = d;
	}
};

//the main min distance function
int minDist()
{
	//creating class object
	sh s(0,0,0);

	//defining the row and cols of the grid
	int n = 4, m = 4;
	//making grid, 1 as a wall, 0 means clear, 2 means source, 3 means destination
	int grid[n][m] = {  {1,0,1,0},
						{0,1,0,0},
						{3,1,0,1},
						{0,0,0,1}};

	//a bool type visited 2d array created to store the posititons
	bool visited[n][m];
	//adding values to bool array
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(grid[i][j] == 1)
				visited[i][j] = true;
			else
				visited[i][j] = false;
		}
	}
	//source position
	s.x = 0; s.y = 3;
	//creating a queue with type class 
	queue<sh> q;
	//pushing the object to queue
	q.push(s);
	//marking the start index as true
	visited[s.x][s.y] = true;
	//implementing bfs algorithm
	while(!q.empty())
	{
		//creating a class object to store the value of the object in the queue
		sh p = q.front();
		//we pop the object from the queue
		q.pop();

		//if the x and y of p is 3 means destination the we return the distance
		if(grid[p.x][p.y] == 3)
		{
			return p.dist;
		}

		//moving up
		if(p.x-1 >= 0 && visited[p.x-1][p.y] == false)
		{
			q.push(sh(p.x - 1 , p.y, p.dist + 1));
			visited[p.x-1][p.y] = true;
		}

		//moving down
		if(p.x + 1 < n && visited[p.x + 1][p.y] == false)
		{
			q.push(sh(p.x + 1, p.y, p.dist + 1));
			visited[p.x + 1][p.y] = true;
		}

		//moving left
		if(p.y - 1 >= 0 && visited[p.x][p.y-1] == false)
		{
			q.push(sh(p.x, p.y - 1, p.dist + 1));
			visited[p.x][p.y-1] = true;
		}

		//moving right
		if(p.y + 1 < m && visited[p.x][p.y + 1] == false)
		{
			q.push(sh(p.x,p.y + 1,p.dist + 1));
			visited[p.x][p.y + 1] = true;
		}
	}
//if no path then return -1
return -1;
}

int main()
{
	cout<<minDist();
	return 0;
}