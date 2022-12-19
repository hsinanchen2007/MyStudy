### 解题思路
最长序列有2种情况：
1. 不包含某个位置的元素：
    - 在这个位置右边
    - 在这个位置左边
2. 包含某个位置的元素。

其中1的两种情况可以通过分治求解，到只有一个元素的时候直接返回就可以了。

第2种情况，可以单独看作一个题目：(这个题目比原题要简单很多，因为限定了一定包含某个元素)
***包含某个元素的最大子序列。***
设这个元素的索引是k，那么包含在[0,k-1]这些数中，包含k-1索引的连续序列中的最大值为maxleft。
在[k,len(arr)]中包含k索引的连续序列为最大值为maxright。
那么这个子问题的最大值是max(maxleft,0)+maxright

然后1.1，1.2，2的最大值就是整个序列的最大子序和。

### 代码

```python3
   def maxSub(self,nums,low,high):
        if high-low==1:
            return nums[low]
        medium=low+(high-low)//2
        left_max=self.maxSub(nums,low,medium)
        right_max=self.maxSub(nums,medium,high)

        low_max=left_sum=0
        for i in range(medium-1,low-1,-1):
            left_sum+=nums[i]
            low_max=max(low_max,left_sum)

        high_max=right_sum=nums[medium]
        for i in range(medium+1,high):
            right_sum+=nums[i]
            high_max=max(high_max,right_sum)

        return max(left_max,right_max,low_max+high_max)
    def maxSubArray2(self,nums):
        return self.maxSub(nums,0,len(nums))
```