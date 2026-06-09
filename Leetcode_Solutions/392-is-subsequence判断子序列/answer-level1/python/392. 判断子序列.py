1. 双指针 
在所有 Python 提交中击败了31.24%的用户
```
if not s: return True
        if not t: return False
        temp_i, _len_s, _len_t = 0, len(s), len(t)
        for i in range(0, _len_s):
            if not s[i] in t[temp_i:_len_t]: return False
            for j in range(temp_i, _len_t):
                if s[i] == t[j]:
                    if i == _len_s - 1:
                        return True
                    temp_i = j + 1
                    break
                temp_i = j + 1

            if temp_i >= _len_t:
                return False
        return False
```

2. 字符串匹配
看到别人写的, 这个比第一个好些。
所有 Python 提交中击败了59.23%的用户
```
class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if not s: return True
        S = list(s)
        for _t in t:
            if not S:
                return True
            if S[0] == _t:
                S.pop(0)
        return not S
```
