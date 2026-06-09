### 解题思路
此处撰写解题思路
考虑3种情况：
1、插入的数字比所有数字都小（直接插入到最前面）；
2、插入的数字比所有的数字都大（直接插入到最后面）；
3、插入的数字在之间：
（1）有相等的数，直接返回位置；
（2）无相等的数，返回插入位置；

具体代码如下：
### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int size = nums.size();
        if(target > nums[size-1]) //插入的数字比所有数字都要大，直接插入到最后
            return size;
        else if(target < nums[0]) //比所有的数字都要小，直接插入到第一个
            return 0;
        for(int i = 0; i < size; i++) //在之间
        {
            if(nums[i] == target) //相等，直接返回位置
                return i;
            else if(nums[i] < target && nums[i+1] > target) //返回插入位置
             return i+1;
        }
        return {};       
    }
};
```