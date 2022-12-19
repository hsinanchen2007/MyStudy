### 解题思路
先创建大小为n*n的二维数组vector,再依次向左、向下、向右、向上...走，直至达到最大数值。

### 代码

```cpp
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> rst(n, vector<int>(n, -1));
        int num = 1;
        int col = 0;
        int row = 0;
        int MaxNum = n * n;
        while (num <= MaxNum)
        {
            //向右
            while ((num <= MaxNum) && (col < n) && (rst[row][col] == -1))
            {
                rst[row][col++] = num++;
            }
            --col;++row;
            //向下
            while ((num <= MaxNum) && (row < n) && (rst[row][col] == -1))
            {
                rst[row++][col] = num++;
            }
            --col;--row;
            //向左
            while ((num <= MaxNum) && (col >= 0) && (rst[row][col] == -1))
            {
                rst[row][col--] = num++;
            }
            ++col;--row;
            //向上
            while ((num <= MaxNum) && (row >= 0) && (rst[row][col] == -1))
            {
                rst[row--][col] = num++;
            }
            ++col;++row;
        }
        return rst;
    }
};
```