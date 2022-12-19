# 题解
## 动态规划

 1. 初始化最小分割次数数组$min\_cut=\{0,1,2,\cdots,n-1\}$，长度为字符串的长度$n$。其中$min\_cut[i]$表示$s[0,\cdots,i]$每个子串都是回文串的分割次数。初始化的含义为，$s[0]$只有一个字符，不需要分割，因此$min\_cut[0]=0$，$s[0,1]$最多需要1次，分成两个单独的字符。$s[0,1,2]$需要三次。以此类推。
 2. 初试化$dp=[[False,\cdots,False],\cdots,[False,\cdots,False]]$,为$n*n$维数组。其中$dp[i][j]$表示$s[i,\cdots,j]$是否为回文串。
 3. 遍历$dp$，子串结束索引$i$，遍历区间$[0,n)$：
 	+ 子串开始索引$i$，遍历区间$[0,j+1)$
 		+ 若$s[i]==s[j]$并且$j-i<2\ or\ dp[i+1][j-1]==True$。解释：动态规划方程含义为，若$s[i]==s[j]$表示子串$s[i,\cdots,j]$的两端相同，则该子串是否为回文串取决于$dp[i+1][j-1]$即（$s[i+1,\cdots,j-1]$）是否为回文串。特殊情况是$j-i<2$，表示长度小于$3$，此时也是满足的。
 			+ $dp[i][j]$（$s[i,\cdots,j]$为回文子串）为$True$ .此时，若$i==0$，开始位置为$0$，说明$s[0,\cdots,j]$为回文串，则此时$min\_cut[j]=0$，表示到$j$位置的子串不需要进行切割，自身就是回文子串。
 			+ 若$i!=0$，说明开始的位置不是$0$，此时$min\_cut[j]=min(min\_cut[j],min\_cut[i-1]+1)$。表示始终为到上一回文串位置的切割次数加1中的最小值。
 	
 4. 返回$min\_cut[-1]$

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

### 复杂度分析
 - 时间复杂度：$O(n^{2})$
 - 空间复杂度：$O(n^{2})$

### Python
```python
class Solution:
    def minCut(self, s: str) -> int:
        min_cut = list(range(len(s)))
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        for j in range(n):
            for i in range(j+1):
                if s[i] == s[j] and (j - i < 2 or dp[i + 1][j - 1]):
                    dp[i][j] = True
                    if i == 0:
                        min_cut[j] = 0
                    else:
                        min_cut[j] = min(min_cut[j], min_cut[i - 1] + 1)
        return min_cut[-1]



```

## 记忆化回溯
![在这里插入图片描述](https://pic.leetcode-cn.com/fe15259d2b418733c8dcee953de3dad5ab95626934667d3612b3a50ea9afee72.png)
 1. 定义回溯函数$minCut(s)$
 	+ 若$s$为回文串，则返回$0$，表示当前子串不需要切割。
 	+ 初试化当前子串的最小切割次数$res=Max$
 	+ 遍历结束索引$i$，遍历区间$[1,n+1)$：
 		+ 若$s[0,\cdots,i-1]$为回文串：$res=min(res,minCut(s[i,\cdots,n-1])+1)$。解释：始终保存最小的切割次数。
	+ 返回$res$
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

### 复杂度分析
 - 时间复杂度：$O(n!)$
 - 空间复杂度：$O(n!)$

### Python
```python
import functools
class Solution:
    @functools.lru_cache(None)
    def minCut(self, s: str) -> int:
        if s == s[::-1]:
            return 0
        ans = float("inf")
        for i in range(1, len(s) + 1):
            if s[:i] == s[:i][::-1]:
                ans = min(self.minCut(s[i:]) + 1, ans)
        return ans

```