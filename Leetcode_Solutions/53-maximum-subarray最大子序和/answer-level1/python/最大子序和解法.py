对于连续数组，我们可以利用一个tmp变量存储累加的和，当累加和大于之前存储的最大和ans时，即对ans进行覆盖，并且需要判断当前的累加和是否小于0，若小于零，则需要对累加和进行清空，这个判断也很好理解，假设记录的累加和为负数的序列为A(A<0)，继续累加的序列为B，那最大子序列显然不可能是A+B，只可能是B，因此对于累加和为负数的时候，应及时舍弃之前已经累加的序列A，即对tmp存储变量进行归零处理。

```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = nums[0]
        tmp = 0
        for num in nums:
            tmp += num
            if tmp > ans:
                ans = tmp
            if tmp < 0:
                tmp = 0

        return ans
```

![QQ截图20200302164748.png](https://pic.leetcode-cn.com/e40f5fbf52773f0d99fb9846401fb9add7599ce4c07d0802716175b24fa4ba0e-QQ%E6%88%AA%E5%9B%BE20200302164748.png)
