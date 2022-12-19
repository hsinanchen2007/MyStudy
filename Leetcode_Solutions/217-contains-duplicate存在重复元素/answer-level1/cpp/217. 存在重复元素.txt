## 先排序，再遍历
**因为不知道数据范围，所以不能开哈希表**
```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len=nums.size();        
        if(len==0) return false;
        sort(nums.begin(), nums.end());
        for(int i=0; i<=len-2; i++){
            if(nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};
```