### 解题思路

leetcode560基础上，矩阵按行就和得到vector
### 代码

```cpp
class Solution {
private:
    int numSubarraySumTarget(vector<int> array, int target)
    {
        int res = 0;
        unordered_map<int, int> sum_map;
        int sum = 0;
        for (int i = 0; i < array.size(); ++i)
        {
            sum += array[i];
            if (sum == target)
            {
                res++;
            }
            if (sum_map.find(sum - target) != sum_map.end())
            {
                res += sum_map[sum - target];
            }
            sum_map[sum]++;
        }
        return res;
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            vector<int> sumarray = matrix[i];
            res += numSubarraySumTarget(sumarray, target);
            for (int j = i - 1; j >= 0; --j)
            {
                for (int k = 0; k < n; ++k)
                {
                    sumarray[k] += matrix[j][k];
                }
                res += numSubarraySumTarget(sumarray, target);
            }
        }
        return res;
    }
};
```