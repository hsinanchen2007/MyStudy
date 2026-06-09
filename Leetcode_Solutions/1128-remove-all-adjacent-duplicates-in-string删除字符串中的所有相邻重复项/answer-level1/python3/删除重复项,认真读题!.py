重复项删除操作会选择**两个**相邻且相同的字母，并删除它们
这里删除的是相邻**两个**, 而非所有的! 所以'aaa'输出为'a'而不是''!!

```
class Solution:
    def removeDuplicates(self, S: str) -> str:
        s = S
        stack = ''
        for s in S:
            if stack and stack[-1]==s:
                stack = stack[:-1]
            else: stack += s
        return stack
```


删除所有相同的
```
class Solution:
    def removeDuplicates(self, S: str) -> str:
        s = S
        stack, l, i = '', len(s), 0
        while i<l:
            if stack and stack[-1]==s[i]:
                while i<l and stack[-1]==s[i]: # 循环内循环一定要保证i<l
                    i += 1
                stack = stack[:-1]
                continue
            stack += s[i]
            i += 1
        return stack
```