### 解题思路
每一次加入新的元素都开一条新的队列，然后将前一个队列的所有元素出队并依次入队到这个新的队列中。

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        if len(self.queue)==0:
            self.queue.append(x)
        else:
            l=[x,]
            for i in self.queue:
                l.append(i)
            self.queue=l
            


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        result = self.queue[0]
        self.queue=self.queue[1:]
        return result


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.queue[0]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if len(self.queue)==0:
            return True
        else:
            return False



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```