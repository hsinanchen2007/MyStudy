### 解题思路
右下左上按照这个顺序创建二维数组即可，我还使用了一个二维数组记录哪些元素已经被初始化。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
// 用来记录哪些元素已经被初始化
		vector<vector<int>> map(n,vector<int>(n,0));
// 返回的结果
		vector<vector<int>> res(n,vector<int>(n,0));
    	if(n==0)
    		return res;
		int size=n*n;
//		x纵坐标，y横坐标 
		int x=0,y=0;
		map[0][0]=1;
		res[0][0]=1;
		for(int i=1;i<size;)
		{
//			右 
			while(y+1<n&&map[x][y+1]==0&&i<size)
			{
				res[x][y+1]=++i;
				map[x][y+1]=1;
				y++;
			}
//			下 
			while(x+1<n&&map[x+1][y]==0&&i<size)
			{
				res[x+1][y]=++i;
				map[x+1][y]=1;
				x++;
			} 
//			左 
			while(y-1>=0&&map[x][y-1]==0&&i<size)
			{
				res[x][y-1]=++i;
				map[x][y-1]=1;
				y--;
			}

//			上 
			while(x-1>=0&&map[x-1][y]==0&&i<size)
			{
				res[x-1][y]=++i;
				map[x-1][y]=1;
				x--;
			}
		}
		return res;
    }
};
```