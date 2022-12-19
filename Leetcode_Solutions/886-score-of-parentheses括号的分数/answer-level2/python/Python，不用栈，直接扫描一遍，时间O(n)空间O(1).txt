用rights和lefts来记录当前没处理的左右括号数，扫描一遍并分情况处理， O(1)空间，O(n)时间。
```python
    def scoreOfParentheses(self, S: str) -> int:
        # 记录未处理的左括号和右括号数
        lefts = rights = i = score = 0
        while i < len(S):
            if S[i] == '(':
                lefts += 1
            else:
                rights += 1
                if rights == lefts or S[i+1] == '(':  # 当右括号数=左括号数或下一字符为左括号时开始处理
                    score += 1 << (lefts-1)  # 累加分数
                    lefts -= rights
                    rights = 0
            i += 1
        return score
```
