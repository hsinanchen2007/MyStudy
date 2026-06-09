### 解题思路

想了好久，只满足了max_value() 和 push_back()两个函数的时间复杂度为O(1),对于pop_front()删除元素来说，怎么能满足O(1)呢? 

后来去看了下官方解释，还可以均摊！瞬间傻了....

好了，接下来，说下我的方法，为了将pop()的复杂度降为O(1)，我选择了双向队列deque，弥补了list的时间复杂度为pop(0)的不足，将其作为容纳全部元素的队列。然后再建一个列表存放递增的数。

注：要时刻满足递增列表的最后一个数为最大值！

时间复杂度分别：
max_value():    O(1)
push_back():    O(1)
pop_front():    最好情况下：O(1),最坏情况下O(n)



### 代码

```python
from collections import deque
class MaxQueue:
    def __init__(self):
        self.stack = deque()
        self.big_stack = []


    def max_value(self) -> int:
        if not self.stack:
            return -1
        return self.big_stack[-1]

    def push_back(self, value: int) -> None:
        if not self.big_stack:
            self.stack.append(value)
            self.big_stack.append(value)
        else:
            self.stack.append(value)
            if value >= self.big_stack[-1]:
                self.big_stack.append(value)

    def pop_front(self) -> int:
        if not self.stack:
            return -1
        else:
            result = self.stack.popleft()
            try:
                #del self.big_stack[self.stack.index(result)]
                self.big_stack.remove(result)
            except ValueError:
                pass
            # 可能在pop后，递增列表为空，此时需要将stack中最大的值，添加进去，要时刻保证big_stack中的最后一个值为最大值。
            if not self.big_stack and self.stack:
                self.big_stack.append(max(self.stack))
        return result

            
    







# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```