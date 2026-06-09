1. 使用哈希表记录出现过的数字下标，节约查询时间。
2. 当a + b == target时，a == target - b。
3. 遍历数组，当前数字为b，如果哈希表中存在 a == target - b，返回 a 和 b 的下标。
4. vector<int> 有列表初始化方法，return {index_of_a, index_of_b} 减少代码长度。

```
class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, const int target) {
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++)
            if (dict.count(target - nums[i]))
                return {dict[target - nums[i]], i};
            else
                dict[nums[i]] = i;
        return {0, 0};
    }
};
```
