### 解题思路
两个queue来回倒即可。

### 代码

```python

class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._qus = [[], []]
        self._push_idx = 0
        self._cur_idx = 0
        self._size = 0

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self._qus[self._push_idx].append(x)
        idx = self._push_idx ^ 0x1
        while self._qus[idx]:
            self._qus[self._push_idx].append(self._qus[idx].pop(0))
        self._cur_idx = self._push_idx
        self._push_idx = idx
        self._size += 1

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        self._size -= 1
        return self._qus[self._cur_idx].pop(0)

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self._qus[self._cur_idx][0]

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return self._size == 0
```