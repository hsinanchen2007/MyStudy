
思路就是：用搜索/回溯法，找错了给它复活的机会，存盘点记作 P0 Q0：
关键注意一下复活的操作：

```python []
class Solution(object):
    def isMatch(self, s, m):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        p = q = 0
        q0 = -1
        while p != len(s) :
            #print(s[p:], m[q:])
            if len(m) != q and m[q] == "*":
                while len(m) != q and m[q] == "*":
                    q0 = q
                    p0 = p
                    q +=1
                    if q == len(m):
                        return True
            if len(m) == q or (m[q] != s[p] and m[q] != "?"):
                if q0 != -1:
                    q = q0+1
                    p ,p0 = p0+1,p0+1
                else:
                    return False
            else:
                q += 1
                p += 1
        #print(s[p:],m[q:])
        while (q < len(m) and m[q] == "*"):
            q += 1
        return q == len(m) and p == len(s)
```
