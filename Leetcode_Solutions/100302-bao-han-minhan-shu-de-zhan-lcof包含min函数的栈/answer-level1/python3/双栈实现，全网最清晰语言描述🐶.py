这题参考了评论才做出来，但是感觉大家描述逻辑时候都很绕口，所以写一下

思路：使用一个辅助栈，长度与原栈相同，***每个位置代表原栈cut到这个长度时的最小值。***

每次push时候同样需要更新辅助栈：新元素更小则append新元素，否则append辅助栈最后一个元素(意味着新加入一个元素后再cut到这一位，最小值还是之前那个)。pop时候同时pop两个栈，这样的结构就可以保证随时查询到最小值。
```python
class MinStack:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.mini = []
        self.stack = []
    def push(self, x: int) -> None:
        self.stack.append(x)
        if self.mini != []:
            if x<self.mini[-1]:self.mini.append(x)
            else: self.mini.append(self.mini[-1])
        else:
            self.mini.append(x)

    def pop(self) -> None:
        self.mini.pop()
        return(self.stack.pop())

    def top(self) -> int:
        return(self.stack[-1])


    def min(self) -> int:
        return(self.mini[-1])

```