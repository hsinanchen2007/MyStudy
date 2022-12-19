class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        stack = []
        result = ''
        for i in S:
            if i == '(':
                stack.append(i)
                if len(stack) > 1:
                    result += '('
            else:
                stack.pop()
                if len(stack) != 0:
                    result += ')'
        return result
![image.png](https://pic.leetcode-cn.com/c16ad36a044039b7d6c41bfa2a9da0171087d4156fdcbd3f565570a78e366de7-image.png)

