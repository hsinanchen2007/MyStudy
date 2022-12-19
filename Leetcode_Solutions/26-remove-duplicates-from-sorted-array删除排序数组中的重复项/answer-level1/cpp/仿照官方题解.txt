### 解题思路
一开始暴力搜索并删除元素，提交时显示运行超时。看了答案，思路比较新颖，并且再一次提交时也忘记考虑size为0的情况。还需多加练习


### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {  
        if(nums.size()==0)
        return 0;
       int i=0;
       for(int j=1;j<nums.size();j++)
       {
           if(nums[j]!=nums[i])
           {
               i++;
               nums[i]=nums[j];
           }
       }
       return i+1;
    }
};
```