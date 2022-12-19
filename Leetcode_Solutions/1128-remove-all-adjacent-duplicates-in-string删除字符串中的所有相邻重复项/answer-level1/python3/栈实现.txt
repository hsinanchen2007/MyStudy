执行用时 :64 ms, 在所有 Python 提交中击败了86.72%的用户

内存消耗 :12.1 MB, 在所有 Python 提交中击败100.00%
的用户

```
class Solution(object):
    def removeDuplicates(self, S):
        """
        :type S: str
        :rtype: str
        """
        stack = list()
        for c in S:
            if stack:
                if stack[-1] != c:
                    stack.append(c)
                else:
                    stack.pop(-1)
            else:
                stack.append(c)
        return ''.join(stack)
```

