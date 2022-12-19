### 解题思路
只要找到横竖两个方向的最小值进行相乘，就可以得到最大值的数量。

### 代码

```cpp
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int m_min = m;
        int n_min = n;
        for(int i = 0; i < ops.size(); i++)
        {
            if(ops[i][0] < m_min)
            {
                m_min = ops[i][0];
            }
            if(ops[i][1] < n_min)
            {
                n_min = ops[i][1];
            }
        }
        return m_min*n_min;
    }
};
```