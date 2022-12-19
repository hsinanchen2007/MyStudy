
- 因为目标是求解连续序列中的缺失数字，所以假定补上该数字，那么新的数组的和是可以知道的，因此采用求和之后与给定数组中的元素相减的思想求解。
- 第一次写完代码之后，想到数组较长的时候，求和可能会产生溢出。为了解决溢出，想到可以分步求和求差，每个元素进行一次加法一次减法。这样就有效减小了可能出现的最大值。
- 代码如下：
```
int missingNumber(vector<int>& nums) 
    {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
            sum = sum + i -nums[i];
        sum = sum + nums.size();
        return sum;
    }
```