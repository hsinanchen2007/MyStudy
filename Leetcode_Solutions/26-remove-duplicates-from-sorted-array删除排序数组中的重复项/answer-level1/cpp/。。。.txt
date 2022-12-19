### 解题思路
此处撰写解题思路

不用管非重复数组后面的部分，只要在前面连续插入就可以，最后返回插入的长度就行了


### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int numc=INT_MIN,insert=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=numc)
            {
                nums[insert++]=nums[i];
                numc=nums[i];
            }
        }
        return insert;
    }
};
```