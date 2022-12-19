### 解题思路
此处撰写解题思路
当flag = 1并且S[i] = '('时，说明是外层括号
当flag = 0 并且S[i] = ')'时，说明是外层括号
![image.png](https://pic.leetcode-cn.com/d54d6cab36e761982d5ef7eb74ae48c7968bf6edf19efa8e2a7c0d3c4ccc33c3-image.png)

### 代码

```python3
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        answer = []
        flag = 0
        length = len(S)
        for i in range(0, length, 1):
            if S[i] == '(':
                flag += 1
                if flag != 1:
                    answer.append(S[i])
            elif S[i] == ')':
                flag -= 1
                if flag != 0:
                    answer.append(S[i])
        
        return ''.join(answer)
            

```