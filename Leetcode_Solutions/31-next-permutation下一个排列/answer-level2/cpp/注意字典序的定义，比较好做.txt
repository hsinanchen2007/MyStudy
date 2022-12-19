### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = 0 , j = nums.size() -1 ;
        for(i = nums.size() - 1;i && nums[i-1] >= nums[i] ; i--);
        if(i)            // 若为最大排列，此时i为0，j为nums.size() - 1;其他情况则定位为i-1 为值
           {
               for(j = nums.size() - 1;i<j && nums[i - 1] >= nums[j];j--);
               swap(nums[i-1],nums[j]);
           }
        reverse(nums.begin() + (j -i == nums.size() - 1 ? 0 : i),nums.end());
    }
};
```