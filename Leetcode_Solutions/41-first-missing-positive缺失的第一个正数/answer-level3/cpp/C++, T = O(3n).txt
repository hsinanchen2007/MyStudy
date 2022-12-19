纪念第一次100%。
共3次循环：
1. 将数组中所有小于等于0或者大于数组长度的数字设为-1，解决了循环2.中的边界问题。
2. 将大于0或小于数组长度的数字放在对应的位置上，目标是设置成[1,2,3,4,5,6,......,numslen]，每次置换后必须i--,避免把后面较小的数换过来却没有计算这个数，同时条件语句中nums[i]!=nums[nums[i]-1]，可以让对应位置的数已经正确的情况下不再置换，而且避免了相邻两个数相同的情况下死循环，如[1,1,...]。
3. 最后一个循环，输出中断的点，即最小正数。

```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int numslen = nums.size();
        int temp;
        
        for(int i=0;i<numslen;i++)
        {
            if(nums[i]<=0||nums[i]>numslen) nums[i] = -1;
        }
        
        for(int i=0;i<numslen;i++)
        {
            if(nums[i]>0&&nums[i]<=numslen&&nums[i]!=nums[nums[i]-1])
            {
                temp = nums[i];
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
                i--;
            }
        }

        for(int i=0;i<numslen;i++)
        {
            if(nums[i]!=i+1) return i+1;
        }
        
        return numslen+1;
    }
};
```
