执行用时 :44 ms, 在所有 Python3 提交中击败了91.02%的用户

算法一般，除7乘10，感觉代码写得很啰嗦，Python没人发我发一个

```class Solution:
    def convertToBase7(self, num: int) -> str:
        negative = False    # 标记，是否为负
        if num < 0:
            num = -num    # 考虑负数的相反数
            negative = True
        res = 0
        bit = 0    # 记录位
        while num >= 7:    # 商大于7时继续
            s = num // 7    # 商
            r = num - 7*s    # 余数
            num = s    # 更新num
            res += (10 ** bit)*r
            bit += 1
        res += 10**bit*num
        if negative: res = -res
        return str(res)
```
