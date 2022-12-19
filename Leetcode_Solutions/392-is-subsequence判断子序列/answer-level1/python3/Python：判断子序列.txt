### 解题思路
并行遍历

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        t_ptr=s_ptr=0
        t_len=len(t)
        s_len=len(s)
        if s_len==0:return True
        while t_ptr<t_len and s_ptr<s_len:
            if s[s_ptr]==t[t_ptr]:
                t_ptr+=1
                s_ptr+=1
            else:
                t_ptr+=1
            if s_ptr==s_len:return True
        return False
```