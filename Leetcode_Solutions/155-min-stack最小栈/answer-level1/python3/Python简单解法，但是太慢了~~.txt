### 思路：
1、代码好理解，但是太慢了。
2、没关系，我们先解决有没有，再解决好不好的问题。
### 代码：
```
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = []

    def push(self, x: int) -> None:
        self.data.append(x)


    def pop(self) -> None:
        self.data.pop()


    def top(self) -> int:
        return self.data[-1]


    def getMin(self) -> int:
        return min(self.data)

```
