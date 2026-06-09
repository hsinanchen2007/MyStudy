这道题不算很难，最简单思路则是列表嵌套，以内列表作为单独一个栈

这题难点在于各种特殊情况，
比如push时候没有栈，你需要新建，或者栈容量小于0，你不能push而是直接return
pop的时候，pop完如果栈空了，你需要删除掉，同理popAt
这么分析下来就单独对每种情况做相应处理
```
class StackOfPlates:

    def __init__(self, cap: int):
        self.cap = cap
        self.fullstack = [[]]

    def push(self, val: int) -> None:
        if self.cap <= 0:
            # 如果初始容量小于0 直接return

            return
        if len(self.fullstack)==0 or len(self.fullstack[-1]) == self.cap:
            # 当栈满了，或没有栈了，则新建一个栈
            self.fullstack.append([])

        self.fullstack[-1].append(val)

    def pop(self) -> int:
        if not self.fullstack or not self.fullstack[-1]:
            return -1

        ans = self.fullstack[-1].pop(-1)
        if len(self.fullstack[-1]) == 0:
            # 如果pop后栈为空，则删除该栈
            self.fullstack.pop(-1)
        return ans

    def popAt(self, index: int) -> int:
        if index >= len(self.fullstack) or not self.fullstack[index]:
            return -1

        popitem = self.fullstack[index].pop(-1)
        if len(self.fullstack[index]) == 0:
            self.fullstack.pop(index)

        return popitem
```
