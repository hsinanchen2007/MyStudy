### 解题思路
此处撰写解题思路

### 代码

```cpp
#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
struct state{
	int x,y,step;
};
class Solution {
private:
	int maxlen=0,col,row,ans=-1;
	int hang[4]={1,-1,0,0},lie[4]={0,0,1,-1};
	bool vis[100][100];    
	int miniDis(vector<vector<int> >& grid,int row,int col)
	{
		memset(vis,0,sizeof(vis));
		queue<state>q;
		state s;
		s.step=0;s.x=row;s.y=col;
		vis[row][col]=1;
        q.push(s);
		while(q.empty()==false)
		{
			state st=q.front();
			q.pop();
			for(int i=0;i<4;i++)
			{
				int x=st.x+hang[i];
				int y=st.y+lie[i];
				if(x<0||x>=grid.size()||y<0||y>=grid[x].size())
					continue;
				if(vis[x][y]==0)
				{
					state ta;
					ta.x=x;ta.y=y;ta.step=st.step+1;
					vis[x][y]=1;
					q.push(ta);
					if(grid[x][y]==1)
						return ta.step;
				}					
			}
		}
		return -1;
	}
public:
    int maxDistance(vector<vector<int> >& grid) {
    	for(int i=0;i<grid.size();i++)
    	{
    		for(int j=0;j<grid[i].size();j++)
    		{
    			if(grid[i][j]==0)
					ans=max(ans,miniDis(grid,i,j));		
    		}
    	}
		return ans;
    }
};
```