### 解题思路
从简单的步骤开始，先仅考虑. ，再在此代码的基础上考虑加入*

### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        '''
        从简单开始，仅考虑.的情况。
        if not bool(p):
            return not bool(s)
        flag_1 = bool(s) and p[0] in {s[0], '.'}
        return flag_1 and self.isMatch(s[1:], p[1:])
        在此基础上添加对*的判断
        '''
        if not bool(p):
            return not bool(s)
        flag_1 = bool(s) and p[0] in {s[0], '.'}
        if len(p) > 1 and p[1] == '*':
            # 判断下一个位置是否是*
            # 如果是，则判断下一步是p+2或者是s+1（需要额外保证当前值满足flag_1
            return flag_1 and self.isMatch(s[1:], p) or self.isMatch(s, p[2:])
        return flag_1 and self.isMatch(s[1:], p[1:])
```