### 解题思路
计算所有  横向相邻  纵向相邻  竖向相邻（z轴）  接触面个数
（仅计算当前元素的左侧或者右侧，上侧或下侧，z轴单面接触直接减）

效率不行，n循环内部操作太多，仅想表达一个思路，终于理解题目了。。
### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        size_t N = grid.size();

        int x, y, z;
        //被遮挡面数
        size_t del = 0;
        //方块数量
        size_t num = 0;
        for(size_t i = 0; i<N; ++i)
        {
            //遍历grid[i]
            for(size_t j=0; j<N; ++j)
            {
                //遍历grid[i][i]
                //x 表示当前格子，y表示右侧格子， z表示下侧格子
                /*
                相当于计算所有  横向相邻  纵向相邻  竖向相邻（z轴）  接触面个数
                */
                x = grid[i][j];
                y = (j+1) == N?0:grid[i][j+1];
                z = (i+1) == N?0:grid[i+1][j];

                if(x > 0)
                {
                    //横向
                    if(y > 0)
                        del += x>y?y:x;
                    //纵向
                    if(z > 0)
                        del += x>z?z:x;
                    //z轴
                    del += x - 1;
                }
                num += x;
            }
        }
        return num*6 - del*2;
    }
};
```