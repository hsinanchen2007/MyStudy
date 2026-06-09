### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        if n == 0:
            return 0
        circle = [i for i in range(n)]
        index = 0
        while n>1 :
            index = (index+m-1)%n
            n = n - 1
            circle.pop(index)
        return circle[0]
```