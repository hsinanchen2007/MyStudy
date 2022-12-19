### 解题思路
队列结构：先进先出、后进后出
堆栈结构：后进先出
用队列实现堆栈，即处理pop元素的问题。在队列中，将插入的元素放入队尾，再利用循环操作将队尾元素放置队头。如此，每次进行元素pop操作时，得到的元素是刚插入的元素，满足堆栈要求。
 1 | 2 | 3 `\Rightarrow` 2 | 3 | 1 `\Rightarrow` 3 | 2 | 1

### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = []


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.queue.append(x)
        q_length = len(self.queue)
        while q_length > 1:
            self.queue.append(self.queue.pop(0)) #反转前n-1个元素，栈顶元素始终保留在队首
            q_length -= 1


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self.queue.pop(0)
        

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.queue[0]



    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if self.queue:
            return False
        else:
            return True



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```