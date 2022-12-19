### 解题思路
![QQ图片20200117102129.png](https://pic.leetcode-cn.com/00703f7e52bf099890f0ecb18d81f895a6dfebd563c0ae1b96e30a91923ba0d5-QQ%E5%9B%BE%E7%89%8720200117102129.png)
+ x ， y 为矩阵型号
1. 当x=1或y=1时，将该矩阵直接输出。
2. x或y大于均大于一时，先处理最外边界，在递归调用，请求处理小一号的矩阵，并传入起始值
3. x或y小于等于0是退出循环

+ 代码可以写的更简洁，但判断条件更复杂.

### 代码

```cpp
class Solution {
public:
    vector<int> rs;
    vector<vector<int>> matrix;
    void get_sequence(int start_x,int start_y,int x,int y)
    {
        if(x<=0||y<=0)
            return;
        if(x==1)
        {
            for(int i=0;i<y;i++)
                rs.push_back(matrix[start_x][start_y+i]);
			return;
        }
        if(y==1)
        {
            for(int i=0;i<x;i++)
                rs.push_back(matrix[start_x+i][start_y]);
			return;
        }
		//首次处理
		for(int i=0;i<y-1;i++)
			rs.push_back(matrix[start_x][start_y+i]);
		for(int i=0;i<x-1;i++)
			rs.push_back(matrix[start_x+i][start_y+y-1]);
		for(int i=0;i<y-1;i++)
			rs.push_back(matrix[start_x+x-1][start_y+y-1-i]);
		for(int i=0;i<x-1;i++)
			rs.push_back(matrix[start_x-i+x-1][start_y]);
        get_sequence(start_x+1,start_y+1,x-2,y-2);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return rs;
        int row = matrix.size();
        int cloumn = matrix[0].size();
		this->matrix = matrix;
        get_sequence(0,0,row,cloumn);
        return rs;
    }
};
```