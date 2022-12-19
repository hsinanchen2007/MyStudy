### 解题思路
此处撰写解题思路


### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if(nums.empty())    return -1;
        for(int i=0; i < nums.size(); i++) {
            if(nums[i]<0||nums[i]>=nums.size())
                return -1;
            while(nums[i] != i) {
                if(nums[i] == nums[nums[i]])
                    return nums[i];
                else
                    swap(nums[i],nums[nums[i]]);
            }
        }
        return -1;
    }

};
```