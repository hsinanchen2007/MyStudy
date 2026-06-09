### 解题思路
我们用一个哈希表来记录和为s的子数组(从下标0开始)出现的次数，
那么我们遍历到第i个数时，计算从0到当前位置的和sum，那么前面若出现和为sum-k的子数组(从0开始)，那么必定存在和为k的子数组(不从0开始)
他们出现的次数相等
### 代码

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int,int> m{{0,1}};
        int sum = 0;
        for(auto& n : nums){
            sum += n;
            res += m[sum-k];
            ++m[sum];
        }
        return res;
    }
};
```