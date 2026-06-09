### 解题思路
使用pyython内置的顺序索引类list完成题目。
push: 尾部追加， 直接使用list 的自带方法 .append(item);
pop: 尾部删除，使用list的自带方法 .pop(-1), 该函数符合弹出指定索引处并有返回值的要求；
top: 索引获取list 的尾元即可；
empty: python 将条件语句中的 '[]','','{}' 均看作假，因此可直接使用list自身作为判断条件； 

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack_Lst = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.stack_Lst.append(x)



    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.stack_Lst.pop(-1)


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.stack_Lst[-1]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if not self.stack_Lst:
            return True
        return False



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```