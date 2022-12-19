### 解题思路
思路简单，只需要注意Python在类内定义共享变量时，需要加self。
`python中类方法的属性需要加self，也就是self.xxx，这个是方法的属性！
类方法的变量不加self，也就是xxx，这个是方法的局部变量，不能被调用，只能在该方法内部使用！

在类中，self只能在方法中使用表示该方法的实例属性，也就是每个实例可以设置不同的值而不会相互影响；在方法下不使用self表示是该方法的局部变量，只能在该方法内使用。

self.xxx是全局的，xxx是局部的对于该方法有效。`

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.l = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.l.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        tmp = self.l[-1]
        del self.l[-1]
        return tmp


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.l[-1]



    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.l)==0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```