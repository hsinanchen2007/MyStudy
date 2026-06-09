### 解题思路
数位DP+KMP

### 代码

```python3
class Solution:
    def findGoodStrings(self, n: int, s1: str, s2: str, evil: str) -> int:
        def getNext(pattern):
            n = len(pattern)
            nxt = [[0]*26 for _ in range(n)]
            nxt[0][ord(pattern[0])-97] = 1
            shadow = 0
            for i in range(1,n):
                for j in range(26):
                    nxt[i][j] = nxt[shadow][j]
                nxt[i][ord(pattern[i])-97] = i + 1
                shadow = nxt[shadow][ord(pattern[i])-97]
            return nxt

        def dfs(s,pos,match,lim): #pos表示当前要查看文本串的第pos位，match表示当前要匹配模式串（evil）的第match位
            if match >= len(evil):return 0
            if pos >= n:return 1
            if (not lim) and (dp[pos][match] != -1): return dp[pos][match]
            up = s[pos] if lim else 'z'
            tmp = 0
            for i in range(ord('a'),ord(up)+1):
                curr = match
                curr = nxt[curr][i-97]
                tmp +=  dfs(s,pos+1,curr,lim and chr(i) == up)
            if not lim:dp[pos][match] = tmp
            return tmp

        dp = [[-1]*len(evil) for _ in range(n)]
        nxt = getNext(evil)

        def solve():
            ans = dfs(s2,0,0,True)
            ans -= dfs(s1,0,0,True)
            if not (evil in s1):ans += 1
            return ans % 1000000007
        return solve()

```
![image.png](https://pic.leetcode-cn.com/50811cd9d51d06043187c120c8d067c54c4388fc9d5e7d40194566db633f2ba3-image.png)
