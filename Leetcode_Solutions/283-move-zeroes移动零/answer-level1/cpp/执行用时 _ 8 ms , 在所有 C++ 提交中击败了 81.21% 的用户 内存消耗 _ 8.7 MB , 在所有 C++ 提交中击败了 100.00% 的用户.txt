### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]!=0)
            {
                nums[idx]=nums[i];
                ++idx;              //位置每次递增
            }
        }
        for(;idx<nums.size();++idx) //最后几个设为0
        {
            nums[idx]=0;
        }
    }
};
```