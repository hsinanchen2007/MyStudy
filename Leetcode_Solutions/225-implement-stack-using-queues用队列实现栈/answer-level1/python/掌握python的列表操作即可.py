### 解题思路
掌握python的列表操作即可

### 代码

```python3
class MyStack:

    def __init__(self):
        self.db = []


    def push(self, x: int) -> None:
        self.db.append(x)


    def pop(self) -> int:
        return self.db.pop()


    def top(self) -> int:
        return self.db[-1]


    def empty(self) -> bool:
        return False if self.db else True



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```