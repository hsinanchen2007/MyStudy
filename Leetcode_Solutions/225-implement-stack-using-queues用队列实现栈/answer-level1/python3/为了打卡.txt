### 解题思路
打卡呦

### 代码

```python3
class MyStack:

    def __init__(self):
        self.q = []

    def push(self, x: int) -> None:
        self.q.append(x)
        q_length = len(self.q)
        while q_length > 1:
            self.q.append(self.q.pop(0)) 
            q_length -= 1

    def pop(self) -> int:
        return self.q.pop(0)

    def top(self) -> int:
        return self.q[0]


    def empty(self) -> bool:

        return not bool(self.q)
```