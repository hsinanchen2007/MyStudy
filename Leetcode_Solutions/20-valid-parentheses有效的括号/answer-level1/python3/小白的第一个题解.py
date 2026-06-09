### 解题思路
从左到右遍历字符串，遇到左括号，则将其存入left[]中，遇到右括号，看其与left[-1]是否匹配，若匹配，则pop掉left[-1]，若不匹配，则return False。遍历完后若left为初始值，则字符串有效。

时间复杂度O(s)，s为字符串长度
（不知道这个方法有没有什么名字，速度还蛮快）
执行用时 :20 ms, 在所有 Python3 提交中击败了99.80% 的用户

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        dic = {')':'(', '(':1,
        ']':'[', '[':1,
        '}':'{', '{':1}
        if len(s)%2 == 1:
            return False
        if len(s) == 0:
            return True
        left = [0]
        for bracket in s:
            if dic[bracket] == 1:
                left.append(bracket)
            elif dic[bracket] == left[-1]:
                left.pop()
            else:
                return False
        return left[-1] == 0
        
```