### 解题思路
新手解题 **4ms **


### 代码

```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
       int max = nums[0],index = 0;

       if(nums.size() < 2)
        return 0;

       for (int i = 0;i<nums.size(); i++) {
           if (max < nums[i]) {
               max = nums[i];
               index = i;
           }
       }

       for (int i=0;i<nums.size();i++) {
           if (max < nums[i] * 2 && i !=index) {
               return -1;
           }
       } 
       return index;
    }
};
```