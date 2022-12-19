### 解题思路
哇，又击败91%的人，leetcode一定是在鼓励我！
很简单啦，就是一个栈操作。如果栈顶元素等于字符，那么就出栈。并且，最重要的是，此时该元素不再入栈。
代码中flag的作用就是这个，不执行append语句。

### 代码

```python3
class Solution:
    def removeDuplicates(self, S: str) -> str:
        stack=[]
        for i in S:
            flag=0
            while stack and stack[-1]==i:
                stack.pop()
                flag=1
            if flag:
                continue
            stack.append(i)
        return ''.join(stack)

```