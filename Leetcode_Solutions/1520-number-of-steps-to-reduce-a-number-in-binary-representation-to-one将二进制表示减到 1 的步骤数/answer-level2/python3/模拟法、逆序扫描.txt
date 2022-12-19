## 解题思路

从后先前扫描，模拟二进制加法和除法

时间复杂度`O(n)`
空间复杂度`O(n)` 可以优化为`O(1)`


## 代码
```python
class Solution:
    def numSteps(self, s: str) -> int:
        tmp = list(s)
        j = len(s) - 1
        res = 0
        while j > 0:
            if tmp[j] == '0':
                res += 1
                j -= 1
            else:
                res += 1
                while tmp[j] == '1' and j >= 0:
                    res += 1
                    j -= 1
                if j >= 0:
                    tmp[j] = '1'
                else:
                    return res
        return res
```