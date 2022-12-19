### 解题思路
这个题目的关键在于对于基本语法和栈概念的掌握。

具体来说，栈是一种先进后出的线性表，每当有一个新元素加入，则将其加入到栈的末端，也就是push操作，当需要获取元素的时候，也是从末端获取，也就是top，弹出一个元素也是类似的。判断一个栈是否为空只需要判断栈的高度是不是0，如果是0，则说明栈内已经没有元素。

实现栈的方法多种多样，这里使用了list。在python中，list已经具有append和pop方法和栈的性质是一致的，可以直接使用，需要进一步实现的是top和empty，这两个方法都可以通过维护栈的高度height来实现，当栈内没有元素时，height定义为-1，每加入一个元素，height加1。那么top就可以直接返回list中下标为height的元素，而empty则可以通过判断height是不是-1来实现。

当然这里为了避免维护一个height，直接通过len()函数来计算list的长度，进而也可以实现类似的操作。

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.sq = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.sq.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        x = self.sq.pop()
        return x;


    def top(self) -> int:
        """
        Get the top element.
        """
        height = len(self.sq)-1
        return self.sq[height]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        length = len(self.sq)
        if(length>0):
            return False
        else:
            return True



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```