### 解题思路
![image.png](https://pic.leetcode-cn.com/3474b280e1f1c042cd328fd83e1b85d1bb37e43c5c97e17ff095885f41d54baf-image.png)
简单的深度优先搜索问题。
遍历所有元素，进入DFS
在DFS内，当找到1，递归遍历该元素的上下左右4个方向的元素，同时利用tmp临时变量保存临时结果。
当临时结果tmp大于res，则res=tmp

注意几个要点
1、遍历所有元素也可以处理成递归，但是不是很推荐，因为用迭代法就已经足够了，用递归反而会增加资源消耗。
2、递归调用周围元素前要先将本身元素置0，否则会进入死循环
3、注意索引范围的问题。
### 代码

```cpp
class Solution {
private:
    int res;
    int ro;
    int co;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ro=grid.size();
        co=grid[0].size();
        res=0;
        int tmp=0;
        for(int i=0;i<ro;i++)
            for(int j=0;j<co;j++)
            {   
                tmp=0;
                DFS(i,j,tmp,grid);
                if(tmp>res) res=tmp;
            }
        return res;
    }
    void DFS(int row,int colume,int &tmp,vector<vector<int>>& grid)
    {
        if(grid[row][colume]==1)
        {
            tmp++;
            grid[row][colume]=0;//置0，防止死循环
            /*递归调用前，要先判断有没有越界*/
            if(row>0) DFS(row-1,colume,tmp,grid);
            if(row<ro-1) DFS(row+1,colume,tmp,grid);
            if(colume<co-1) DFS(row,colume+1,tmp,grid);
            if(colume>0) DFS(row,colume-1,tmp,grid);
        }
    }
};
```