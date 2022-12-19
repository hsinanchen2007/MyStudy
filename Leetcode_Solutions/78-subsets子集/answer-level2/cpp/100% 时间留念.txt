第一次 时间超过100%，特此留念。

对于 n 个数的排列，共有 `2^n` 个结果，循环一遍，对于每个数进行位运算去除对应的 1。

```cpp
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int total = 1 << nums.size();
        vector<vector<int>> result(total);
        for (int i = 0; i < total; i++)
            for (int j = i, k = 0; j; j >>= 1, k++)
                if (j & 1 == 1)
                    result[i].push_back(nums[k]);
        return result;
    }
};
```