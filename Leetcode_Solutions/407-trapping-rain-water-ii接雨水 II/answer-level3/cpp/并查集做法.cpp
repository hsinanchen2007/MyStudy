### 解题思路
使用并查集从最低点开始往上处理。每次维护当前集合的边界线。如果边界线上有同一高度的集合，就合并当前集合。

然后每次将当前计算该层集合的贡献之后，将该集合的最低高度设置成边界线上的最低点

### 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn=115;
using point = pair<int,int>;
int pre[maxn*maxn];
int union_size[maxn*maxn];
struct Block
{
	list<point>side;
	int height;
}block[maxn*maxn];
int find(int x)
{
	int r=x;
	while(pre[r]!=r)
	{
		r=pre[r];
	}
	int i=x,j;
	while(i!=r)
	{
		j=pre[i];
		pre[i]=r;
		i=j;
	}
	return r;
}
void join(int x,int y)
{
	int r_x=find(x),r_y=find(y);
	if(r_x!=r_y)
	{
		pre[r_y]=r_x;
		union_size[r_x]+=union_size[r_y];
		union_size[r_y]=0;
	}
}
int n,m;
int hash_point(point p)
{
	return (p.first)*(m+2)+p.second;
};
bool check(point p)
{
	return p.first>=1 && p.second>=1 && p.first<=n && p.second<=m;
};
struct cmp{
	bool operator()(int a,int b) const
	{
		return block[a].height>block[b].height;
	}
};
class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap)
	{
		n=(int)heightMap.size();
		m=(int)heightMap[0].size();
		int dirx[4]={0,1,-1,0};
		int diry[4]={1,0,0,-1};
		priority_queue<int,vector<int>,cmp>q;
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=m+1;j++)
			{
				int hash_id=hash_point({i,j});
				//cout<<i<<" "<<j<<" "<<hash_id<<endl;
				pre[hash_id]=hash_id;
				block[hash_id].side.clear();
				if(check({i,j}))
				{
					union_size[hash_point({i, j})]=1;
					block[hash_id].height=heightMap[i-1][j-1];
					for(int k=0; k<4; k++)
						block[hash_id].side.push_back({i+dirx[k], j+diry[k]});
					q.push(hash_id);
				}
				else
				{
					union_size[hash_point({i, j})]=0;
					block[hash_id].height=-1;
				}
			}
		int ans=0;
		while(!q.empty())
		{
			int now_node=q.top();
			//cout<<now_node<<"  ****  "<<find(now_node)<<"  "<<block[now_node].height<<endl;
			q.pop();
			auto &side=block[now_node].side;
			if(find(now_node)!=now_node || block[now_node].height<0)
			{
				continue;
			}
			for(auto it=side.begin();it!=side.end();it++)
			{
				int next_node=find(hash_point(*it));
				//cout<<"next height:  "<<next_node<<" "<<block[next_node].height<<endl;
				if(find(next_node)!=now_node && block[next_node].height==block[now_node].height)
				{
					join(now_node,next_node);
					//cout<<"join:"<<now_node<<" "<<next_node<<endl;
					for(auto j:block[next_node].side)side.push_back(j);
				}
			}

			int min_side_height=1<<25;
			for(auto it=side.begin();it!=side.end();)
			{
				//cout<<find(hash_point(*it))<<" "<<" : "<<block[find(hash_point(*it))].height<<endl;
				if(!check(*it))
				{
					min_side_height=-1;
					block[now_node].height=-1;
					it++;

				}
				else if(find(hash_point(*it))==now_node)
					it=side.erase(it);
				else
				{
					min_side_height=min(min_side_height,block[find(hash_point(*it))].height);
					it++;
				}
			}

			if(min_side_height!=-1)
			{
				ans+=(min_side_height-block[now_node].height)*union_size[now_node];
				//cout<<min_side_height<<" cal "<<block[now_node].height<<endl;
				block[now_node].height=min_side_height;
				q.push(now_node);
			}
			block[now_node].height=min_side_height;
		}
		return ans;
	}
};
```