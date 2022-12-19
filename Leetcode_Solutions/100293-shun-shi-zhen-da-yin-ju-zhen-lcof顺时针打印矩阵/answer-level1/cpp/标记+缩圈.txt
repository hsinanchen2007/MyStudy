### 解题思路
相当于矩形里面嵌矩形
![无标题.png](https://pic.leetcode-cn.com/e2b07a9052da9b4e18650d36f3a557f99dcc63dc205c675f03330dba973038f1-%E6%97%A0%E6%A0%87%E9%A2%98.png)


### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)return{};
        vector<int> res;
        vector<vector<bool>> flag(matrix.size(), vector<bool>(matrix[0].size(), false));  //用于标记是否已访问
        //初始矩形框
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;
        while (left <= right && top <= bottom)
        {
            int l = left, r = right;
            int t = top + 1, b = bottom - 1;  //务必注意这里，根据图来理解！！！
            while (l <= right && !flag[top][l])
            {
                //从左到右
                flag[top][l] = true;
                res.push_back(matrix[top][l++]);  //固定top
            }
            while (t < bottom && !flag[t][right])
            {
                //从上到下
                flag[t][right] = true;
                res.push_back(matrix[t++][right]);  //固定right
            }
            while (r >= left && !flag[bottom][r])
            {
                //从右到左
                flag[bottom][r] = true;
                res.push_back(matrix[bottom][r--]);
            }
            while (b > top && !flag[b][left])  //这里不要写错了！！b>top!!!
            {
                //从下到上
                flag[b][left] = true;
                res.push_back(matrix[b--][left]);
            }
            //缩圈
            ++left;
            --right;
            ++top;
            --bottom;
        }
        return res;
    }
};
```