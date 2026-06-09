### 解题思路
设置一个计数器 count，左括号 +1，右括号减 1，等于 0 则找到外括号的终点。并且 0 后面的一个括号肯定也是外括号，可以直接跳过。

### 代码

```python3
class Solution(object):
    def removeOuterParentheses(self, S):
        """
        :type S: str
        :rtype: str
        """
        target =''
        count, i = 1, 1
        while i< len(S):
            if S[i]=="(":
                count = count + 1
            else:
                count = count - 1
            if count == 0:
                i = i + 2
                count = count + 1
                continue
            target = target + S[i]
            i = i + 1
        return target

```