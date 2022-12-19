![image.png](https://pic.leetcode-cn.com/f30b6c7153ff4d00056a8a6018fa8e10940cf78b0b364da0b2c626db339a6640-image.png)


```
'''
贪心策略
用栈来进行配对，只有配对的括号留下来，其他括号全部删掉
'''


class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        pos = set()
        for i, ch in enumerate(s):
            if ch not in ['(', ')']:
                continue

            if len(stack) == 0 or not (stack[-1][0] == '(' and ch == ')'):
                stack.append((ch, i))
            else:
                pos.add(stack[-1][1])
                pos.add(i)
                stack.pop(-1)

        ans = []
        for i, ch in enumerate(s):
            if ch not in ['(', ')'] or i in pos:
                ans.append(ch)

        return ''.join(ans)
```
