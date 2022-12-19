### 解题思路
使用列表模拟队列
init创建列表
pop使用list.pop()方法
top使用列表切片
empty使用当前列表和[]做比较
重点是push：添加元素后把元素移到最后(使用append(pop(0))),感谢[@xilepeng](/u/xilepeng/)给我的思路

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.param = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.param.append(x)
        param_len = len(self.param)
        while param_len > 1:
            self.param.append(self.param.pop(0))
            param_len -= 1
        


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.param.pop(0)


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.param[0]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.param == []



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```