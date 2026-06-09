### 解题思路
题意需要让最小元素位于栈顶，实现小顶堆即可满足。
堆排的精髓在于两个方法：
1. swim() 元素上浮
在有新元素入栈时，通过将该元素与其父元素比较，将该元素上浮至堆合适位置。
需要上浮节点的索引为 index 时，父节点索引为 (index-1)//2。
```
    def swim(self, index):
        while index > 0 and self.stack[index] < self.stack[(index-1)//2]:
            self.stack[index], self.stack[(index-1)//2] = self.stack[(index-1)//2], self.stack[index]
            index = (index-1)//2
```

2. sink() 元素下沉
在将最小元素出栈时，将堆顶元素（索引为 0）与堆尾元素交换，pop出栈。
此时堆顶元素的变动使得整个堆不再符合小顶堆的结果，将该节点与两个子节点比较下沉至堆合适位置。
由于堆的根节点索引从 0 开始，所以左右孩子节点的索引为 2*index+1 和 2*index+2。
```
    def sink(self, index):
        n = len(self.stack)
        while 2*index+1 < n:
            j = 2*index+1
            if j < n-1 and self.stack[j] > self.stack[j+1]:
                j += 1
            if self.stack[index] <= self.stack[j]:
                break
            self.stack[index], self.stack[j] = self.stack[j], self.stack[index]
            index = j
```

### 代码

```python3
class SortedStack:

    def __init__(self):
        self.stack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        self.swim(len(self.stack)-1)

    def pop(self) -> None:
        if not self.stack:
            return
        self.stack[0], self.stack[-1] = self.stack[-1], self.stack[0]
        self.stack.pop()
        self.sink(0)

    def peek(self) -> int:
        return self.stack and self.stack[0] or -1

    def isEmpty(self) -> bool:
        return not self.stack

    def sink(self, index):
        n = len(self.stack)
        while 2*index+1 < n:
            j = 2*index+1
            if j < n-1 and self.stack[j] > self.stack[j+1]:
                j += 1
            if self.stack[index] <= self.stack[j]:
                break
            self.stack[index], self.stack[j] = self.stack[j], self.stack[index]
            index = j
    
    def swim(self, index):
        while index > 0 and self.stack[index] < self.stack[(index-1)//2]:
            self.stack[index], self.stack[(index-1)//2] = self.stack[(index-1)//2], self.stack[index]
            index = (index-1)//2


# Your SortedStack object will be instantiated and called as such:
# obj = SortedStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.peek()
# param_4 = obj.isEmpty()
```