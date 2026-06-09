
```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numIndex;  // 保存上次遇见该数时，该数对应的下标。由于下标一定是递增的，所以一定存在最小差值出现在相邻下标，不需要存储所有的下标
        for(int i = 0; i < nums.size(); ++i) {
            int newIndex = i + 1; // 让索引+1，从而使默认值0代表该键还没有出现
            int lastIndex = numIndex[nums[i]];
            if(lastIndex != 0 && newIndex - lastIndex <= k)
                return true;

            numIndex[nums[i]] = newIndex;
        }
        return false;
    }
};
```
