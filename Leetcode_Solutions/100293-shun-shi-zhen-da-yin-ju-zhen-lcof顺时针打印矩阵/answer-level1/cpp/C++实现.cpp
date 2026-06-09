### 解题思路
用row  col 限制每次访问的最大值  也就是二维数组的右下角
用mini minj 限制每次开始访问的最小值  也就是二维数组的左上角

每次顺时针遍历完一次后 row col各自减小1  mini minj各自增加1 
然后在当前这个范围内在进行顺时针遍历

在每次开始之前 判断row col  与 mini minj 的值 
如果mini minj的值中有任意一个比 row col 的值减一  还要大 说明已经全部遍历完全部

如果只有一行或一列  顺时针遍历简化为一个for循环的变脸

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> fin;
        if(matrix.empty() == 1)
            return fin;
        int row = matrix[0].size();
        int col = matrix.size();
        //mini 限制 i , minj 限制 j
        int mini = 0, minj = 0;
        int i = 0, j = 0;
        while(1)
        {
            if(row - 1 < minj || col - 1 < mini)
            {
                break;
            }
            //如果只有一行
            if(col - mini == 1)
            {
                for(int k = minj; k < row; ++k)
                {
                    fin.push_back(matrix[mini][k]);
                }
                break;
            }
            if(row - minj == 1)
            {
                for(int k = mini; k < col; ++k)
                {
                    fin.push_back(matrix[k][minj]);
                }
                break;
            }
            while(j < row)
            {
                fin.push_back(matrix[i][j]);
                ++j;
            }
            --j;
            ++i;
            while(i < col)
            {
                fin.push_back(matrix[i][j]);
                ++i;
            }
            --i;
            --j;
            while(j >= minj)
            {
                fin.push_back(matrix[i][j]);
                --j;
            }
            ++j;
            while(i > mini + 1)
            {
                --i;
                fin.push_back(matrix[i][j]);
            }
            row--;
            col--;
            i = ++mini;
            j = ++minj;
        }
        return fin;
    }
};
```