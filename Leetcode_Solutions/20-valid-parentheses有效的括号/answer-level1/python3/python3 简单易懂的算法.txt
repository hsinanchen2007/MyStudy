### 解题思路
执行用时 :32 ms, 在所有 Python3 提交中击败了90.20%的用户
内存消耗 :13.4 MB, 在所有 Python3 提交中击败了6.08%的用户
### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        """
        使用了栈的思想，如果是左符号，则入栈，
        如果是右符号，则出栈并判断是否匹配。
        最后判断栈中是否还有元素即可
        """
        left = ["[", "(", "{"]
        right = ["]", ")", "}"]
        m = {"]": "[", ")": "(", "}": "{"}
        stack = []
        for c in s:
            if c in left:
                stack.append(c)
            elif c in right:
                if len(stack) == 0 or stack.pop() != m[c]:
                    return False
        return len(stack) == 0

```