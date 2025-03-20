#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, land[410][410] = {0};
int dx[8] = {-2, -2, -1, 1, 2, 2, -1, 1}, dy[8] = {-1, 1, 2, 2, -1, 1, -2, -2};
struct point
{
	int lx, ly, step;
};
queue<point> q;
int main()
{
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			land[i][j] = -1;
		}
	}
	land[x][y] = 0;
	q.push(point{x,y,0});
	int step = 1;
	while(!q.empty())
	{
		point p = q.front();
		q.pop();
		for(int i = 0; i < 8; i++)
		{
			int nx = p.lx + dx[i], ny = p.ly + dy[i];
			if(nx < 1 ||  ny < 1 || nx > n+1 || ny > m+1) continue;
			if(land[nx][ny] == -1)
			{
				land[nx][ny] = p.step+1;
				q.push(point{nx,ny,p.step+1});
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			printf("%-5d", land[i][j]);
		}
		printf("\n");
	}
	return 0;
}
