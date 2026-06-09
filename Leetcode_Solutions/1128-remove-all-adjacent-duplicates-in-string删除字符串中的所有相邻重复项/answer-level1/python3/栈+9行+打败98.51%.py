* 执行用时 : 88 ms, 在Remove All Adjacent Duplicates In String的Python3提交中击败了98.51% 的用户
* 内存消耗 : 13.2 MB, 在Remove All Adjacent Duplicates In String的Python3提交中击败了100.00% 的用户

```
class Solution:
    def removeDuplicates(self, S):
        stack = [',']
        for i in S:
            if i == stack[-1]:
                stack.pop()
            else:
                stack.append(i)
        return ''.join(stack[1:])
```