### 解题思路
思路参考 [@jyd](/u/jyd/)
- 这道题主要的难点在于，想到用四个边界来限定每次循环的范围，以及考虑如何收缩边界。
- 然后，注意判断越界以及矩阵的行列别写错了。
- 最后就是特殊情况，[]以及[[]]。保持鲁棒性。
### C++代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if(matrix.empty()||matrix[0].empty())
            return v;
        int l = 0;
        int r = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;
        while(1)
        {
            for(int i = l;i<=r;i++)
            {
                v.push_back(matrix[top][i]);
            }
            if(++top > bottom)
                break;
            for(int i = top;i<=bottom;i++)
            {
                v.push_back(matrix[i][r]);
            }
            if(--r < l)
                break;
            for(int i = r;i >= l;i--)
            {
                v.push_back(matrix[bottom][i]);
            }
            if(--bottom < top)
                break;
            for(int i = bottom;i>=top;i--)
            {
                v.push_back(matrix[i][l]);
            }
            if(++l > r)
                break;
        }
        return v;
    }
};
```