### 解题思路
需要注意的地方就是队列时先入先出

### 代码

```python
class MaxQueue(object):

    def __init__(self):
        self.q = []


    def max_value(self):
        if not self.q:
            return -1
        return max(self.q)


    def push_back(self, value):
        self.q.append(value)


    def pop_front(self):
        if not self.q:
            return -1
        return self.q.pop(0)




```