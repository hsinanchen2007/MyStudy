### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
	private:
		int Earth2water(vector<vector<int> >&grid,int row,int col)
		{
			grid[row][col]=0;
			int ans=1;
			for(int i=-1;i<=1;i++)
			{
				for(int j=-1;j<=1;j++)
				{
					if((i==0&&j!=0)||(i!=0&&j==0))
					{
						if(row+i<grid.size()&&col+j<grid[row+i].size())
						{
							if(grid[row+i][col+j]==1)
							{
								ans+=Earth2water(grid,row+i,col+j);	
							}
						}	
					}	
				}
			}
			return ans;
		}
public:
    int maxAreaOfIsland(vector<vector<int> >& grid) {
		int ans=0;
		for(int i=0;i<grid.size();i++)
		{
			for(int j=0;j<grid[i].size();j++)
			{
				if(grid[i][j]==1)
				{
				   ans=max(ans,Earth2water(grid,i,j));
				}
			}
		}
		return ans;
    }
};
```