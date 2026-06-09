### 解题思路
没想到排序居然比unorder_map还要快

### 代码

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    int nsize=nums.size();
    if (nsize==0) return false;
    sort(nums.begin(),nums.end());
    for (int i=0;i<nsize-1;i++) {
        if (nums[i]==nums[i+1])
            return true;
    }
    return false;
    }
};
```