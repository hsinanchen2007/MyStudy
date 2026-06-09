![image.png](https://pic.leetcode-cn.com/26d45262a72a6c50d0c3d9b219ddc14b6baaadaf4fabef113fa495af44b91d6e-image.png)


```
'''
栈应用
'''

class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = []
        for ch in s:
            if len(stack) == 0:
                stack.append([ch, 1])
            else:
                if ch == stack[-1][0]:
                    stack[-1][1] += 1
                    if stack[-1][1] == k:
                        stack.pop(-1)
                else:
                    stack.append([ch, 1])

        ans = ''
        for node in stack:
            ans += node[0] * node[1]

        return ans
```
