### 解题思路
生成一个数组，每次删除索引+m-1,取余是防止超界。

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        circle = [i for i in range(n)]
        index = m % len(circle) -1
        # print(circle[index])
        del circle[index]
        while len(circle)>1:
            index = (index + m-1) % len(circle)
            # print(circle[index])
            del circle[index]
        return circle[0]
```