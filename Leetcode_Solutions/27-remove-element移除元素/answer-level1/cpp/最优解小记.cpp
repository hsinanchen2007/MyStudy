### 解题思路
对序列每一个元素循环判断，同时记录相同个数。如果相同则当前元素舍弃，不相同则将当前元素复制到对应位置。对应位置利用相同个数和当前位置进行计算。

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i,le_n=nums.size(),i_1=0;
        for(i=0;i<nums.size();i++)
        {
            
            if(nums[i]==val)
            {
                i_1++; 
            }
            else
            {
                nums[i-i_1]=nums[i];
            }
        }
        return le_n-i_1;
    }
};
```