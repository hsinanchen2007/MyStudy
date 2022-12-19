### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++) if(nums[i]==nums[i+1]) return nums[i];
        return 0;
    }
};
```