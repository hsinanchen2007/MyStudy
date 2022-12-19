用了内置库，不用内置库用纯数组也可以实现，就是`insert(0, value) pop(0)`比`appendleft(value) popleft()`略慢点，其他基本差不多。

```python []
class MyCircularDeque:

    def __init__(self, k: int):
        self.q = collections.deque(maxlen=k)

    def insertFront(self, value: int) -> bool:
        return len(self.q) < self.q.maxlen and (self.q.appendleft(value) or True)

    def insertLast(self, value: int) -> bool:
        return len(self.q) < self.q.maxlen and (self.q.append(value) or True)

    def deleteFront(self) -> bool:
        return self.q and (self.q.popleft() or True)
    
    def deleteLast(self) -> bool:
        return self.q and (self.q.pop() or True)
        
    def getFront(self) -> int:
        return not self.q and -1 or self.q[0]
    
    def getRear(self) -> int:
        return not self.q and -1 or self.q[-1]

    def isEmpty(self) -> bool:
        return not self.q

    def isFull(self) -> bool:
        return len(self.q) == self.q.maxlen
```


![image.png](https://pic.leetcode-cn.com/3fbae6e689da6f4006e2a0cee11de69b87054c4de1150a563b902c4c02b8b794-image.png)
