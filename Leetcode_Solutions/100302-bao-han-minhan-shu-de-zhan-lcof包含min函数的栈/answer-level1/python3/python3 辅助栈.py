### 解题思路
(1)栈Stack1正常存储元素，正常入栈出栈；辅助栈min_Stack 自底至顶递减，弹出最小值时，输出min_Stack[-1]
(2) 关键在于min_Stack 如何入栈和出栈操作，才能保证自底至顶递减
(3) 入栈时，如果min_Stack 为空，或者 当前元素x<= min_Stack[-1],即栈顶元素，将x入栈，否则不入栈，因为始终要保证栈顶为最小值
(4) 出栈时，需要判断，Stack1弹出的值是否是最小值，即判断min_Stack[-1]==Stack[-1],如果相等，min_Stack.pop(-1),执行出栈操作
这题和求队列中的最大值类似 [https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/]() 入栈稍有不同
### 代码

```python3
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.Stack1,self.min_Stack=[],[]

    def push(self, x: int) -> None:
        self.Stack1.append(x)
        #将入栈元素的最小值放于min_satck的栈顶
        if not self.min_Stack or x<=self.min_Stack[-1]:
            self.min_Stack.append(x)
    def pop(self) -> None:
        if self.min_Stack[-1]==self.Stack1[-1]:
            self.min_Stack.pop()
        self.Stack1.pop()

    def top(self) -> int:
        if self.Stack1:
            return self.Stack1[-1]
        return []
        
    def min(self) -> int:
        return self.min_Stack[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.min()


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.min()
```