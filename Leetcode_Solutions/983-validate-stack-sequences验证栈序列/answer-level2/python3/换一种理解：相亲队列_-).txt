（其实我个人不推荐这种引入场景的理解方式，但是有些时候逻辑确实很难看明白。所以可以借助场景理解下题意，但是最后一定要回归题目本身）

`popped`为**排队等待**的女嘉宾，
`pushed`为**依次入场**的男嘉宾，
数字相同就携手离开，否则继续等待。

对应到这个题就是：

男1入场，女4在前，男1等待 --> 男：(1)  女：(4, 5, 3, 2, 1)
男2入场，女4在前，男2等待 --> 男：(1,2)  女：(4, 5, 3, 2, 1)
男3入场，女4在前，男3等待 --> 男：(1,2,3)  女：(4, 5, 3, 2, 1)
男4入场，女4在前，对4溜走 --> 男：(1,2,3)  女：(5, 3, 2, 1)
**(注意男4走，男3上前; 女4走，女5上前；而3与5不对应，继续等待)**
男5入场，女5在前，对5溜走 --> 男：(1, 2, 3)  女：(3, 2, 1)
最后，男：(1, 2, 3)  女：(3, 2, 1)， 迎面走来，对3，对2，对1分别溜走。

最后发现没有剩下男生和女生， 返回True, 相亲成功:-)

Python代码如下
```python
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        if not pushed: return True
        stack = []
        for num in pushed:
            stack.append(num)
            while stack and stack[-1] == popped[0]:
                popped.pop(0)
                stack.pop()
        return len(stack) == len(popped) == 0
```
其中`stack`是难嘉宾等待区， `popped`就是女嘉宾等待区。
