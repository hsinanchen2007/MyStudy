### 解题思路
中心扩展法

极简思路：

- 首先每个单独的字母都算作回文数 len(s)
- 其次 计算一下每个位置对应的回文半径r (r+1)//2 实际上即为子回文数的总和
- 两者相加即为所有回文数 数量

### 代码

```

class Solution:
    def countSubstrings(self, s: str) -> int:
        def check(i,j,len_s):
            while i>=0 and j<len_s:
                if s[i]==s[j]:
                    i-=1
                    j+=1
                else:
                    break
            return j-1-i
        if s:
            res=0
            len_s=len(s)
            for i in range(len_s):
                k_11=check(i,i,len_s)
                k_22=check(i,i+1,len_s)
                if k_11>0:
                    res+=k_11>>1
                if k_22>0:
                    res+=k_22>>1
            return res+len_s
        return 0
```