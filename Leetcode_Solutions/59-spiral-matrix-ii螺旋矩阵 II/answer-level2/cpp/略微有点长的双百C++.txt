### 解题思路
螺旋考虑每行每列填充的边界就可以
![image.png](https://pic.leetcode-cn.com/2e7af180570f5e66f61587db1fd7430a9aeb7032c54f4cd5af1063cd5f874785-image.png)


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int i = 0, j = 0, max_i = n - 1, max_j = n - 1;
        int min_i = 0, min_j = 0;
        int cur = 1, max_cur = n * n;
        while (cur <= max_cur)
        {
            while (j <= max_j)
            {
                ret[i][j++] = cur++;
            }
            min_i++;
            j--;
            i++;
            while (i <= max_i)
            {
                ret[i++][j] = cur++;
            }
            max_j--;
            i--;
            j--;
            while (j >= min_j)
            {
                ret[i][j--] = cur++;
            }
            max_i--;
            j++;
            i--;
            while (i >= min_i)
            {
                ret[i--][j] = cur++;
            }
            min_j++;
            i++;
            j++;
        }
        return ret;
    }
};
```