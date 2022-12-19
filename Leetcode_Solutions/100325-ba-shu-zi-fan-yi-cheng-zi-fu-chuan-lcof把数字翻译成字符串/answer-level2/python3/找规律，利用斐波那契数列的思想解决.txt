![TIM截图20200314170757.png](https://pic.leetcode-cn.com/dc5925bfb89175b2cbf2d2184cc673695973be92910dff7b167e11d5bf283a0c-TIM%E6%88%AA%E5%9B%BE20200314170757.png)

思路：将数字转为字符串，比如数值12338
f(0)=1
f(1)=1
f(12)=f(0) + f(1) 
f(123)=f(12) + f(1)
f(1233)= f(123) 由于33不在0-25范围内，则只用一项
f(12338) = f(1233)

```class Solution:
    def translateNum(self, num: int) -> int:
        if num < 10: return 1
        nums = str(num)
        prePre = 1
        pre = 1
        l = 1 # 位数，从首位开始
        cur = 1
        while l < len(nums):
            if nums[l-1:l+1] >= '10' and  nums[l-1:l+1] <= '25':
                cur = prePre + pre
            else:
                cur = pre
            prePre = pre
            pre = cur
            l += 1
        return cur```