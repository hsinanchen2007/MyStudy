

### 代码

```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1) return 0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=i;
        sort(nums.begin(),nums.end());
        if(nums[nums.size()-1]>=nums[nums.size()-2]*2) return m[nums[nums.size()-1]];
        return -1;
    }
};
```