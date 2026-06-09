### 解题思路
典型的贪心算法问题：每次都取t中找有没有和s相等的字母，有就直接计数
最后返回计数的结果和s的长度是否相等即可。

### 代码

```

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        ##特殊情况处理：
        if not s:
            return True

        ##贪心算法
        si = 0
        ti = 0
        len_s = len(s)
        len_t = len(t)
        res = 0 #[]
        while si<len_s and ti<len_t:
            if s[si]==t[ti]:
                # res.append(t[ti])
                res+=1
                si+=1
                ti+=1
            else:
                ti+=1
        # res_s = "".join(res)
        # print(res_s)
        return res==len_s

```