### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     if(nums.size() == 1||nums.empty())
     return nums.size();
     int i = 0,j,len = nums.size(),count = 1;
     for(j = 1;j<len;j++)
     {
         if(nums[i]!=nums[j])
         {
            nums[++i] = nums[j];
            count = 1;
         }
         else if(nums[i] == nums[j] && count == 1)
         {
             nums[++i] = nums[j];
             ++count;
         }
     }
     nums.resize(i+1);
     return nums.size();
    }
};
```