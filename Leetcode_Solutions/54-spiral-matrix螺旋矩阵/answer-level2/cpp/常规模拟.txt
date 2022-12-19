### 解题思路
申请一个二维矩阵规格同matrix记录是否走过matrix中的元素，初始化为零走过置一，按照右下左上的顺序记录即可。

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int rows=matrix.size();
		vector<int> res;
    	if(matrix.size()==0)
    		return res;
		int cols=matrix[0].size(); 
		int size=rows*cols;
//map用来记录是否走过matrix中的元素
		vector<vector<int>> map(rows,vector<int>(cols,0));
//		x纵坐标，y横坐标 
		int x=0,y=0;
		res.push_back(matrix[x][0]);
		map[x][0]=1;
		for(int i=1;i<size;)
		{
//			右 
			while(y+1<cols&&map[x][y+1]==0&&i<size)
			{
				res.push_back(matrix[x][y+1]);
				map[x][y+1]=1;
				y++;
				i++;
			}
//			下 
			while(x+1<rows&&map[x+1][y]==0&&i<size)
			{
				res.push_back(matrix[x+1][y]);
				map[x+1][y]=1;
				x++;
				i++;
			} 
//			左 
			while(y-1>=0&&map[x][y-1]==0&&i<size)
			{
				res.push_back(matrix[x][y-1]);
				map[x][y-1]=1;
				y--;
				i++;
			}

//			上 
			while(x-1>=0&&map[x-1][y]==0&&i<size)
			{
				res.push_back(matrix[x-1][y]);
				map[x-1][y]=1;
				x--;
				i++;
			}
		}
		return res;
    }
};
```