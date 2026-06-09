### 解题思路
使用list实现stack的功能。
1. push: 直接用append，在末尾加上元素。
2. pop：截取列表的第一个到倒数第二个元素，返回末尾元素。
3. top：返回末尾元素。
4. empty：判断list长度是否为0。

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if len(self.q)>0:
            tmp = self.q[-1]
            self.q=self.q[:-1]
            return tmp
        else:
            return False



    def top(self) -> int:
        """
        Get the top element.
        """
        if len(self.q)>0:
            return self.q[-1]
        else:
            return False


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if len(self.q)==0:
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