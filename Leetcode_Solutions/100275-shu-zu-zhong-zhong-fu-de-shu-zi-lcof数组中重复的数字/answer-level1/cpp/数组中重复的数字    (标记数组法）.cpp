class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
       vector<int> record(nums.size());
       for(int i=0;i<nums.size();i++){
           if(record[nums[i]]==1)
                return nums[i];
           record[nums[i]]=1;
       }
       return  -1;
    }
};

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

注意到所有数字都在0~n-1之间，那么显然我们可以设计一个标记数组长度为你n,并且所有初始值均为0.我们将数组的下标定义为nums中的值，当nums出现一个值我们将标记数组相应位置的0赋值为1，当nums存在时，则标技数组的值已经为1，显然，可以直接输出nums.

这是一种用空间换时间的一种做法。