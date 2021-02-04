#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
// BFS

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 25;

int n, m;
char g[N][N];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};


int bfs(int sx, int sy)
{
	queue<PII> q;
	q.push({sx, sy});
	// 标记为障碍物
	g[sx][sy] = '#';
	int res = 0;


	while (q.size())
	{
		auto t = q.front();
		q.pop();
		res ++;

		for (int i = 0; i < 4; i ++)
		{
			int x = t.x + dx[i], y = t.y + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] != '.')
				continue;

			g[x][y] = '#';
			q.push({x, y});
		}
	}
	return res;
}

int dfs(int x, int y)
{
	int res = 1;
	g[x][y] = '#';
	for (int i = 0; i < 4; i ++)
	{
		int a = x + dx[i], b = y + dy[i];
		if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] == '.' )
			res += dfs(a, b);
	}
	return res;
}


int main(){
	while (cin >> m >> n, n || m)
	{
		for (int i = 0; i < n; i ++) 
			for (int j = 0; j < m; j ++)
				cin >> g[i][j];
			

		int x, y;
 		for (int i = 0; i < n; i ++) 
			for (int j = 0; j < m; j ++)
			
				if (g[i][j] == '@')
				{
					x = i;
					y = j;
				}
		cout << dfs(x,y) << endl;
	}
	return 0;
}