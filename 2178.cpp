//https://www.acmicpc.net/problem/2178
//2016-08-09

#include <cstdio>
#include <queue>
using namespace std;
int n,m;
int a[100][100];
int dist[100][100];
bool check[100][100];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&a[i][j]);
		}
	}

	queue<pair<int, int> > q;
	q.push(make_pair(0,0));
	check[0][0] = true;
    dist[0][0] = 1;
    while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(0<=nx && n > nx && 0 <= ny &&  m > ny)
			{
				if(check[nx][ny] == false && a[nx][ny] == 1)
				{
					q.push(make_pair(nx,ny));
					dist[nx][ny] = dist[x][y] + 1;
					check[nx][ny] = true;
				}
			}
		}	
	}
	printf("%d\n",dist[n-1][m-1]);
	return 0;
}
