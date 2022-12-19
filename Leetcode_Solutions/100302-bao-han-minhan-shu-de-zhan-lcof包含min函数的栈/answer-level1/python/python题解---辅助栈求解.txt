### 使用辅助栈来保存最小值
1. 设定基础栈 stack 和 辅助栈 min_stack.
2. push()函数---最初的时候第一个元素就是最小的元素直接将第一个元素放入进两个栈中,接下来再有元素 x 进入时我们需要判断 min_stack 中的最后一个元素和 x 的大小,如果 x > min_stack[-1],那么我们需要将 min_stack[-1] 加入栈 min_stack 中, 如果 x > min_stack[-1] 那么就将 x 加入栈中.
3. pop()函数---两个栈需要同时pop()
4. top()函数---直接返回 stack 的第一个元素即可
5. min()函数---直接返回 min_stack[-1]


### 代码

```python
class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_stack = []


    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.stack.append(x)
        if not self.min_stack:
            self.min_stack.append(x)
        else:
            if self.min_stack[-1] < x:
                self.min_stack.append(self.min_stack[-1])
            else:
                self.min_stack.append(x)

    def pop(self):
        """
        :rtype: None
        """
        self.stack.pop()
        self.min_stack.pop()



    def top(self):
        """
        :rtype: int
        """
        if not self.stack:
            return []
        else:
            return self.stack[-1]


    def min(self):
        """
        :rtype: int
        """
        return self.min_stack[-1]



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.min()
```