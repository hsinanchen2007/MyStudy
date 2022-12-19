### 解题思路
int():函数返回整数
math.sqrt():返回平方根
其他和T167.Two Sum一样

### 代码

```python
class Solution(object):
    def judgeSquareSum(self, c):
        i = 0
        j = int(math.sqrt(c))
        while (i<=j):
            sqSum = i*i + j*j
            if sqSum == c:
                return True
            elif sqSum > c:
                j -= 1
            else:
                i += 1
        return False
```