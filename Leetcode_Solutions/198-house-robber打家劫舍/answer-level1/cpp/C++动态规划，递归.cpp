### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int* currentMax = new int[nums.size()];
        currentMax[0] = nums[0];
        currentMax[1] = max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++)
        {
currentMax[i]= max(*max_element(currentMax,currentMax+i-1)+nums[i],currentMax[i-1]);
        }
        return currentMax[nums.size() - 1];
 
    }
};
```