### 解题思路
用主辅两个queue，元素都存在主queue里面，当pop元素时，辅助queue保存主queue的元素(除了主queueu最后的元素)

### 代码

```python
from Queue import Queue

class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        # 主 queue，全部元素都存在里面
        self.q = Queue()
        # 辅助 queue, 当pop时，保存主queue的元素，除了主queueu最后的元素
        self.assist_q = Queue()

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.q.put(x)

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        while self.q.qsize() > 1:
            self.assist_q.put(self.q.get())
        # 拿到主queue最后一个元素，就是最新push进queue的元素
        ans = self.q.get()
        # 主 副 queue，互换
        self.q, self.assist_q = self.assist_q, self.q
        return ans

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        ans = self.pop()
        self.q.put(ans)
        return ans

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return self.q.qsize() == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```