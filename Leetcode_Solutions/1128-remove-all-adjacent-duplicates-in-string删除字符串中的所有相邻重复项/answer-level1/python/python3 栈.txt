遍历一遍字符串，新的字符压入栈之前与栈顶元素比较，若相同，弹出栈尾元素；若不相同，将字符压入栈。
```
class Solution:
    def removeDuplicates(self, S: str) -> str:
        stack = []
        for i in S:
            if stack and stack[-1] == i:
                stack.pop()
            else:
                stack.append(i)
        return ''.join(stack)
```
