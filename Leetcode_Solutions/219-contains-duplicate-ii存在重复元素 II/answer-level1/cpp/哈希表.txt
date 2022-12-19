### 解题思路
维护一个哈希表，要么符合条件return，要么更新值

### 代码

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i=0; i<nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end() && i-mp[nums[i]] <= k) return true;
            else mp[nums[i]] = i;
        }
        return false;
    }
};
```