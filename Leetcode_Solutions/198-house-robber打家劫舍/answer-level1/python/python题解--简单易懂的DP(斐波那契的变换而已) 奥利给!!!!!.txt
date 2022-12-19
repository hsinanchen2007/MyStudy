### 解题思路
![image.png](https://pic.leetcode-cn.com/25bdcaa43fbfe6a5b8fc93723cffcddd42e2a556d9da0d64ac8f1997a5c9edfe-image.png)

- 题目的意思转换一下就是整个数组求不相离取值的最大和,也就是让我们跳跃式的取值,看看最终怎么取出来的值的和是最大的
- 我么设定`f(n)`为当遇到第`n`间房子的时所获取的最大值
- 线面分为两种情况讨论下:
1. 当偷不偷第`n`间房子时:
- 这时所获的最大值也就是在前一间房子获得的值也就是`f(n)=f(n-1)`
2. 当选择偷第`n`间房子时
- 由于我们偷了第`n`间房子,根据题目我们不能偷去相邻的房子,所以我们最终火的值为第`n-2`间房子的值加上我们第`n`间的值,即`f(n)=f(n-2)+nums[n] `
- 我们所要求的是在第`n`间房子时获取的最大值,所以整理下整个递推公式为`f(n)=max(f(n-1),f(n-2)+nums[n])`

- 大家可以看下这个公式是不是和斐波那契的很像,只是加上了一些限定条件而已,所以说复杂的问题都是能找到根源的,慢慢理解就好了,我也是菜鸡,大家一起进步吧!!!   奥利给  哈塞黑

### 代码

```python
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 注释的这一部分是递归的代码
        # def result(temp, nums):
        #     if temp == 0:
        #         return 0
        #     if temp == 1:
        #         return nums[0]
            
        #     return max(result(temp-1,nums), result(temp-2,nums)+nums[temp-1])
        # return result(len(nums), nums)

        # 非递归代码
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        f_0 = 0
        f_1 = nums[0]
        for i in range(1,len(nums)):
            f_n = max(f_1, f_0+nums[i])
            f_0 = f_1
            f_1 = f_n
        return f_n






```