### 解题思路

此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/c7b477225d9a3a0330708b621c5f047de22a017daf4f7211c1c4ff02ae73254a-image.png)
8方向就是利用两个for循环，得到新的坐标需要进行特判坐标是否合法，该点是否被访问过或者是障碍物。
这里为了节约内存将记录结点访问状态和当前距离以及grid合并，0表示没有访问过，大于0表示访问过或者有障碍物

### 代码

```cpp
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		typedef pair<int,int> PII;//存行数和列数索引
        int n=grid.size();
		if(grid[0][0]==1 || grid[n-1][n-1]==1)
			return -1;
		grid[0][0]=1;//这里grid和visit合并，0表示没有访问过,>0表示访问过的距离或者有障碍
		queue<PII> qu;
		qu.emplace(0,0);
		while(!qu.empty()){
			PII u=qu.front();
			qu.pop();

			int nx=u.first,ny=u.second;
			for(int i=-1;i<=1;i++)
				for(int j=-1;j<=1;j++){
					int x=nx+i,y=ny+j;
					if(x<0 || x>n-1 ||y<0 || y>n-1 || grid[x][y])
						continue;
					grid[x][y]=grid[nx][ny]+1;
					qu.emplace(x,y);
				}
		}
		return grid[n-1][n-1]==0 ? -1:grid[n-1][n-1];
    }
};
```