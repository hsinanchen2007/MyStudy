### 解题思路
用计数器判断是否是最外层括号，当计数器为0的时候则是最外层括号

### 代码

```python3
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        result = ''
        count = 0
        for i in S:
            if i == ')':
                count -= 1
            if count >= 1:
                result += i
            if i == '(':
                count += 1
        return result

执行用时 :28 ms, 在所有 python3 提交中击败了99.92%的用户
内存消耗 :12.9 MB, 在所有 python3 提交中击败了100.00%的用户