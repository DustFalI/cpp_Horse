#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, land[410][410] = {0};
int dx[8] = {-2, -2, -1, 1, 2, 2, -1, 1}, dy[8] = {-1, 1, 2, 2, -1, 1, -2, -2};//偏移变量
struct point
{
	int lx, ly, step;//每个位置单独存储自己的步数，方式同一步数的多个位置因for循环而错乱
};
queue<point> q;
int main()
{
	scanf("%d%d%d%d", &n, &m, &x, &y);//养成好习惯，每个文件用同一种输入输出
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			land[i][j] = -1;//初始化为-1
		}
	}
	land[x][y] = 0;//起点标记为0步
	q.push(point{x,y,0});//起点入队，当前位置的步数为0
	while(!q.empty())
	{
		point p = q.front();
		q.pop();
		for(int i = 0; i < 8; i++)
		{
			int nx = p.lx + dx[i], ny = p.ly + dy[i];
			if(nx < 1 ||  ny < 1 || nx > n+1 || ny > m+1) continue;
			if(land[nx][ny] == -1)//-1代表没有被标记
			{
				land[nx][ny] = p.step+1;//找到，标记为下一步到达点
				q.push(point{nx,ny,p.step+1});//将下一步作为起点步
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			printf("%-5d", land[i][j]);//-5表示每个元素占5个位置
		}
		printf("\n");
	}
	return 0;
}
