```cpp
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M.front().size();
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int num = 0, sum = 0;
                for (int _i = max(0, i-1); _i <= min(m-1, i+1); ++_i)
                {
                    for (int _j = max(0, j-1); _j <= min(n-1, j+1); ++_j)
                    {
                        sum += M[_i][_j];
                        ++num;
                    }
                }
                result[i][j] = sum / num;
            }
        }
        return result;
    }
};
```


执行用时 :168 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :17.6 MB, 在所有 C++ 提交中击败了79.09%的用户