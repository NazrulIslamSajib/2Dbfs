#include<bits/stdc++.h>
using namespace std;
pair<int,int>s;
pair<int,int>d;
int n,m;
string grid[100];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
bool isvalid(int x,int y)
{
    return x<n && x>=0 && y<m && y>=0 && grid[x][y]!='#';
}
int main()
{
    int i,j;
    cin>>n>>m;
    //grid = vector<string>grid(n);
    int level[100][100];
     memset(level,-1,sizeof(level));
    //level[s.first][s.second]=0;
    queue<pair<int,int>>q;
    //q.push(s);
    for(i=0;i<n;i++)
    {
        cin>>grid[i];
    }
    for(i=0;i<n;i++)
    {
       // cin>>grid[i];
        for(j=0;j<m;j++)
        {
            if(grid[i][j]=='S')
            {
                s.first=i;
                s.second=j;
                level[s.first][s.second]=0;
                q.push(s);
            }
            if(grid[i][j]=='D')
            {
                d.first=i;
                d.second=j;
            }
        }
    }


    while(!q.empty())
    {
        pair<int,int>u;
        u=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            pair<int,int>v={u.first+dx[i],u.second+dy[i]};
            if(isvalid(v.first,v.second) && level[v.first][v.second]==-1)
            {
                level[v.first][v.second]=level[u.first][u.second]+1;
                q.push(v);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<level[i][j]<<" ";
        }
        cout<<endl;
    }

  return 0;


}
