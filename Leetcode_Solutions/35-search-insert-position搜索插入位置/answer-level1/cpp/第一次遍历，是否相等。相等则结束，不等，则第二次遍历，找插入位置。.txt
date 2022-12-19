有相等的直接输出位置
没有 输出比它大的位置 即是它要插入的位置

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int flag=1;
        int weizhi;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]==target)
           {
               flag=0;
               weizhi=i;
               return weizhi;
           }
         

       } 
        if(flag)
           {
              for(int i=0;i<nums.size();i++)
                {
           if(nums[i]>target)
                    {
               weizhi=i;
               return weizhi;
                }
                 }       
           }
           return weizhi;
    }
};
```