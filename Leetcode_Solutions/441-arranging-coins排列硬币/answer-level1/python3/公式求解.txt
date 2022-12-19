### 解题思路
思路参考“[直接求k(k+1) /2 = n的解，然后取整即可，一行代码，0ms，击败100%](https://leetcode-cn.com/problems/arranging-coins/solution/zhi-jie-qiu-kk1-2-nde-jie-ran-hou-qu-zheng-ji-ke-y/)”，将Java代码转成Python。

### 代码

```python
import math
class Solution:
    def arrangeCoins(self, n: int) -> int:
        return int(math.sqrt(2) * math.sqrt(n + 0.125) - 0.5)
```

### 测试代码

```Python
if __name__ == '__main__':
    number1 = 5051
    s = Solution()
    print(s.arrangeCoins(number1))
```
