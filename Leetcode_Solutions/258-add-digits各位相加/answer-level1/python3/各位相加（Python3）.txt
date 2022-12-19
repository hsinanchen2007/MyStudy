#### 思路
使用`res`保存当前相加的结果，如果不是个位数（>=10），则进行新一轮相加。
#### 代码
```
class Solution:
    def addDigits(self, num: int) -> int:
        if num <10:
            return num
        while num >= 10:
            res = 0
            while num > 0:
                res += num % 10
                num //= 10
            num = res
        return res
```
#### 复杂度分析
- 时间复杂度：O(N^2)
- 空间复杂度：O(1)
