### 解题思路
给“(”、“)”配对，如果temp中是满对，如“(()())”，就删除外层的括号对，传给result。

### 代码

```python
class Solution(object):
    def removeOuterParentheses(self, S):
        temp, result = "", ""
        start_bracket = 0
        for char in S:
            temp += char
            if char == '(':
                start_bracket += 1
            else:
                start_bracket -= 1
            if start_bracket == 0:
                result += temp[1:-1]
                temp = ""
        return result
```