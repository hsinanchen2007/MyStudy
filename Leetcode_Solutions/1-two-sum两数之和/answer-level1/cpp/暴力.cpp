### 解题思路
跨考小白第一次刷题，直接i，j遍历两遍数组，只要i，j下标不一样并且和等于target即可。

时间复杂度应该是O（n^2）,以后待优化……

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        for(int j=0;j<nums.size();j++)
        {
            int k=nums[i]+nums[j];
            if(i!=j&&k==target)
            {
               return {i,j};
            }
        }
        return {};
    }
};
```