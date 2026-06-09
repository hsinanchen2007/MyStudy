### 思路

**栈**

```
这里我犯了个错，pop 时记得要把栈顶元素弹出，不能只是返回，一定要弹出。
```

##### Python3代码

```python
class CustomStack:

    def __init__(self, maxSize: int):
        self.size = 0
        self.maxSize = maxSize
        self.customStack = []

    def push(self, x: int) -> None:
        if self.size < self.maxSize:
            self.customStack.append(x)
            self.size += 1

    def pop(self) -> int:
        if self.size == 0:
            return -1
        temp = self.customStack[self.size - 1]
        # 要把栈顶元素弹出去，即删除栈顶元素
        del self.customStack[self.size - 1]
        self.size -= 1
        return temp

    def increment(self, k: int, val: int) -> None:
        for i in range(min(k, self.size)):
            self.customStack[i] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/1381-Design-a-Stack-With-Increment-Operation/1381.py)