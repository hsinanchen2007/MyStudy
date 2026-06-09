### 解题思路
使用双指针，从两头开始实验。
唯一需要注意的是，右侧边界可以设置折半，来缩短搜索时间。

### 代码

```python3
import math

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        if c < 0:
            return False
        i = 0
        j = int(math.sqrt(c))
        while i <= j:
            s = i*i + j*j
            if s == c:
                return True
            elif s > c:
                j -= 1
            else:
                i += 1
        return False
```