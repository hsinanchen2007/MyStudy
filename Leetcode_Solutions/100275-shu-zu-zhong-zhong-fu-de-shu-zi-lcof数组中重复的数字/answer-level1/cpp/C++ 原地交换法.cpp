### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int res = -1;
        if(nums.empty())  return -1;
        for(int i = 0; i < nums.size(); i++)
        {
            while(i != nums[i])
            {
                if(nums[i] != nums[nums[i]])
                {
                    swap(nums[i],nums[nums[i]]);
                }
                else
                {
                    return nums[i];
                }
            } 
        }
        return -1;
    }
};
//将遍历到的数字与数组对应位置所存数字进行交换（循环），直到让相应数字归位，
//或者发现已有数字在其应在位置(说明重复），则返还重复数字