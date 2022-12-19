用记录:record [0,1,1,0,...], 1:表示此位置括号有效，扫描一次得到record
再次扫描record得到最长的连续的1的个数

```python
class Solution(object):
    def longestValidParentheses(self, s):
        stack = []
        length = len(s)

        # 记录:record [0,1,1,0,...], 1:表示此位置括号有效
        record = [0] * length
        for i in range(length):
            cur = s[i]
            if cur == '(':
                stack.append(i)
            elif cur == ')':
                if len(stack) > 0:
                    j = stack.pop()
                    record[i] = 1
                    record[j] = 1

        # [0, 1, 1, 0] -> [0, 1, 2, 0]
        maxL = 0
        for i in range(1, length):
            if record[i] > 0:
                record[i] = record[i-1] + 1
                if record[i] > maxL:
                    maxL = record[i]

        return maxL

```
