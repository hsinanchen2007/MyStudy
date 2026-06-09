### 解题思路
排列组合知识

### 代码

```python
class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        #由于数字只有0~9，因此无重复出现数字的长度仅有10位
        if n == 0:return 1
        if n == 1:return 10
        if n == 2:return 91
        ans = 91
        ans_i = 81
        for i in range(2,min(n,10)):
            ans_i *= (10 - i) 
            ans += ans_i
        return ans
```