### 解题思路（打卡）
各位大神真的好厉害！！！


### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.__items = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.__items.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.__items.pop()


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.__items[-1]



    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.__items == []



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```