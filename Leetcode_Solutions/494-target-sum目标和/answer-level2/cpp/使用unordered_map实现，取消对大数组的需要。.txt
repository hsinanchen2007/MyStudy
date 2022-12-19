```
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // sum, count 
        unordered_map<int, int> first;
        // when first is looping, it can't modify itself
        unordered_map<int, int> second;
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (S > sum || S < -sum || ((sum + S) & 1))
            return 0;

        S = (sum + S) / 2;

        second[0] = 1;
        first = second;
        for (int i = 0; i < nums.size(); ++i) {
            for (auto j = second.begin(); j != second.end(); ++j) {
                first[j->first + nums[i]] += j->second;
            }
            second = first;
        }

        return first[S];
    }
};
```

使用unordered_map实现，取消大数组的需要。