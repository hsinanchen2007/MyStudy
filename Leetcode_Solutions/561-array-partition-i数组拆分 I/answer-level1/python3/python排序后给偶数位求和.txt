从题目中我们知道 两个分为一组 取最小和
就相当于我们先给这个数组排序 然后去偶数位的和
最后时间和空间都超过100

```
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums = sorted(nums)
        sum = 0
        for i in range(0,len(nums)):
            if i%2 == 0:
                sum =sum + nums[i]

        return sum
```
