### 解题思路
1、用两个队列，一个是final，一个是tmp用于倒腾；
2、对于入栈，直接final.append，更更新top
3、对于出栈，因为我们不能直接弹出队列尾部元素，那么只能先把final全放到tmp，留下最后一个元素作为栈顶弹出；
4、然后需要交换final和tmp，不用全部复制元素，只需要交换final和tmp的指针即可；

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        # 这里用于入队的栈
        self.final = []
        # 用它倒腾
        self.tmp = []
        # 栈顶元素
        self.top_element = None

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        # 直接push到final就可以了
        self.final.append(x)
        self.top_element = x

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        # 先把final都倒腾到tmp，然后留下的最后一个final就是结果
        top_tmp = None
        while len(self.final) > 1:
            top_tmp = self.final.pop(0)
            self.tmp.append(top_tmp)
            self.top_element = top_tmp

        # 这是最后一个元素，直接弹出
        result = self.final.pop(0)

        # 交换新的final和tmp
        swap = self.final
        self.final = self.tmp
        self.tmp = swap

        return result

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.top_element

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.final) == 0

        
```