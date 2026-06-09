设置两个串遍历的时候相邻字母改变标志flag，flag不一致说明变化不一致，设置字典两个字符串对应的字母不一致也表明结构不一样。

```
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        dic = {}
        if len(s) != len(t):
            return False
        if len(s) == 0 or len(s) == 1:
            return True

        dic[s[0]] = t[0]
       
        for i in range(1,len(s)):
            flag_s = False
            flag_t = False
            if s[i] != s[i-1]:
                flag_s = True
            if t[i] != t[i-1]:
                flag_t = True
            if flag_s != flag_t:
                return False
            if s[i] not in dic:
                dic[s[i]] = t[i]
            else:
                if dic[s[i]] != t[i]:
                    return False
                else:
                    continue

        return True


```
