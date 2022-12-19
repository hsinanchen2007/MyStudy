### 解题思路
法一：修改数组顺序

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if (nums.size()==0) return -1;

        int temp;
        for(int i=0;i<nums.size();i++)
        {
            if (i!=nums[i])
            {
                if (nums[i]==nums[nums[i]]) return nums[i];
                else{
                temp=nums[i];
                nums[i]=nums[temp];
                nums[temp]=temp;}
            }    
        }
        return -1;


        
    }
};
```