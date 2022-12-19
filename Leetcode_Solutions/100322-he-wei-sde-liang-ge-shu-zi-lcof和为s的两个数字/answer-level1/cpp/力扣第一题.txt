

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;

        while(nums[lo]+nums[hi]!=target)
        {
            if(nums[lo]+nums[hi]>target) hi--;
            if(nums[lo]+nums[hi]<target) lo++;
        }

        return {nums[lo],nums[hi]};
    }
};
```