### 解题思路
循环中考虑循环的终止节点, 同时对是否存在可能结果进行判断

### 代码

```cpp
class Solution {
public:
    void combineHelp(vector<vector<int>>& rst, vector<int>& temp, int k, int n, int begin, int sum)
    {
        if (sum == n)
            rst.push_back(temp);
        else
        {
            for (int i = begin; i <= 9 - (k-1); ++i)
            {
                if (n-sum >= k*i && n-sum <= k*9)
                {
                    temp.push_back(i);
                    combineHelp(rst, temp, k-1, n, i+1, sum+i);
                    temp.pop_back();
                }
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        if (n < k*1 || n > k*9)
            return {};
        if (k == 0) return {};
        vector<vector<int>> rst;
        vector<int> temp;
        combineHelp(rst, temp, k, n, 1, 0);
        return rst;
    }
};
```