    1. 刚了解动态规划的基本思想，主要有以下思路过程，以供参考，欢迎指正。

#法一：每次先计算包含前i个元素的最大连续子序列的和，计入列表result[i]，到第i+1个元素时，计算包含第i+1个元素的最大连续子序列的和，并与result[i]比较取较大值，这样result就记录了到第i个元素时的最大连续子序列的和，并用到了上一步计算出的result[i]，符合动态规划的思想，代码如下：
```
        L=len(nums)
        result=[nums[0]]
        for i in range(1,L):
            Max=nums[i]
            for j in range(i,-1,-1):
                if sum(nums[j:i+1]) > Max:
                    Max= sum(nums[j:i+1])
            Max=max(result[i-1],Max)
            result.append(Max)
        return result[-1]
```
#此法通过了199个，然后超时了，作进一步改进。

#法二：上述方法超时的原因在于，每次都要计算包含i+1个元素的最大连续子序列。参考了大神们的思路后
，做了进一步改进。
```
        Sum=0
        Max=nums[0]
        for num in nums:
            Sum += num
            if Sum > Max:
                Max = Sum
            if Sum < 0:
                Sum = 0       
        return Max
```
#当Sum大于之前的Max时，自然是要重新赋值，重点在于为何每当Sum<0时，要将Sum重置为0，个人理解是，当加到第i个元素Sum<0时，第i+1个元素不论正负，加上此时的Sum都会变小，所以将Sum重置为0，而Max的值保存下来了


#法3：还是动态规划，借鉴大佬的
```
        for i in range(1, len(nums)):
            nums[i]= nums[i] + max(nums[i-1], 0)
        return max(nums)
```
#用nums数组去记录以i终点（包含i)的最大连续子序列。若num[i-1]小于0时，最大连续子序列就是num[i]本身，反之则加上之前的num[i-1]。题目要求的最大连续子序列的最后一个元素可能是0，1，2...n，而nums记录了以0，1，2...n为终点的最大连续子序列，则答案一定就在nums中，只需输出最大即可。
