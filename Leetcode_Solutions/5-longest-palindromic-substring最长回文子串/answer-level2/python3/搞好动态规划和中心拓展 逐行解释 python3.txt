# 题解
## 动态规划

 1. 特判，当$s$的长度为$1$或者$0$时，返回$s$。
 2. 初试化最长回文子串的开始索引$start$和最长长度$max\_len=1$
 3. 初试化$dp$数组，为$n*n$，全部初始化为$False$。$dp[i][j]$表示$s[i-j]$是否为回文串。
 4. 将$dp$中，所有单个字符处都是回文串，置为$True$。$s$中若相邻的字符串相同，则同样将着两个字符对应的位置置为$True$。即遍历$s$：
 	+ $dp[i][i]=True$，表示单个字符一定是回文串。
 	+ 若$i<n-1\ and\ s[i]==s[i+1]$，表示相邻的字符相同。则$dp[i][i+1]=True$，并更新最长回文子串的开始索引$start=i$和长度$max\_len=2$
 
 5. 此时，从长度$3$，开始遍历，遍历区间$[3,n+1)$，表示所有最长子串可能的长度。因为长度为$1$和$2$的已经在上一步找完了。对于可能的长度$l$：
 	+ 从索引$0$开始遍历，遍历区间$[0,n-l+1)$，对于开始索引$i$。**遍历区间解释：**因为开始索引为$i$，长度为$l$，则子串右侧索引为$i+l-1$，为了保证不越界，$i+l-1<n$，则$i<n-+1l$。
 		* 令子串右侧索引$r=i+l-1$
 		* 若满足$s[i]==s[r]\ and\ dp[i+1][r-1]==True$。表示子串$s[i+1,...,r-1]$为回文且$s[i]==s[r]$，说明$s[i,...,r]$也是回文。则此时，更新$dp[i][r]=True$，并更新最长子串开始索引$start=i$和长度$max\_len=l$
 
 6. 返回$s[start,...,start+max\_len-1]$

### 复杂度分析
 - 时间复杂度：$O\left(n^{2}\right)$
 - 空间复杂度：$O(n^{2})$

### Python

```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if(not s or len(s)==1):
            return s
        n=len(s)
        dp=[[False]*n for _ in range(n)]
        max_len=1
        start=0
        for i in range(n):
            dp[i][i]=True
            if(i<n-1 and s[i]==s[i+1]):
                dp[i][i+1]=True
                start=i
                max_len=2
        for l in range(3,n+1):
            for i in range(n+1-l):
                r=i+l-1
                if(s[i]==s[r] and dp[i+1][r-1]):
                    dp[i][r]=True
                    start=i
                    max_len=l
        return s[start:start+max_len]
```
## 中心拓展法
回文串的中心可能是一个字符或者两个字符。因此，我们遍历每一个字符和每一对相邻的字符

 1. 特判，若$s$长度为$1$或$0$，返回$s$
 2. 初试化最长回文子串的开始索引和结束索引$start=0,end=0$
 3. 拓展函数$expand(l,r)$，$l$表示传入中心字符的左界，$r$表示传入字符中心的右界。
 	+ 若满足条件$0<=l\ and\ r<n\ and s[l]==s[r]$，执行循环：向两侧拓展$l-=1$，$r+=1$
 	+ 返回回文串的长度$r-l-1$。**注意！为什么是$r-l-1$?**，若不满足循环条件，则最后结束时，$l$多减了1，$r$多加了1。另外一种情况，就是传入两个字符时，不满足循环条件，此时$l+1-l-1=0$，表示不是回文串。
 4. 遍历$s$，遍历区间$[0,n)$：
 	+ 中心为一个字符的拓展后长度$len\_1=expand(i,i)$
 	+ 中心为两个字符的拓展后长度$len\_2=expand(i,i+1)$
 	+ 较长的子串长度$len\_long=max(len\_1,len\_2)$
 	+ 若满足$len\_long>end-start+1$，表示当前长度大于之前的最长长度，更新$start$和$end$
 		* $start=i-(len\_long-1)//2$
 		* $end=i+len\_long//2$
 **解释！start和end的更新公式**
 $//$表示向下取整
 因为有两种情况，拓展中心为一个字符或者两个字符。无论是一个还是两个，令字符串长度$(len-1)//2$总能得到拓展中心左侧元素的个数。同理，令$len//2$总能得到拓展中心右侧的个数。
 
 5. 返回$s[start,...,end]$

### 复杂度分析
 - 时间复杂度：$O\left(n^{2}\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expand(l,r):
            while(0<=l and r<n and s[l]==s[r]):
                l-=1
                r+=1
            return r-l-1
        if(not s or len(s)==1):
            return s
        n=len(s)
        start=0
        end=0
        for i in range(n):
            len1=expand(i,i)
            len2=expand(i,i+1)
            len_long=max(len1,len2)
            if(len_long>end-start):
                start=i-(len_long-1)//2
                end=i+(len_long)//2
        return s[start:end+1]
```
