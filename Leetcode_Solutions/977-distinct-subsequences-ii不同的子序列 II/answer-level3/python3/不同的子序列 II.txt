### 解题思路
例如字符串  ababc
现象：按照字符串遍历顺序，最后一个字符加到已经生成的子序列中，发现当出现b第二次出现 b 时候出现相同的子序列
a 
ab  b 
aba  ba aa 
abab bab aab, abb bb, ab, b  (ab,b 重复了)             
        

分析归纳：假定已有子序类 substr,  后续遇到a+xxx+a ，对于 这两个a 都有可能产生 substr+a 的字串。产生重复

方法一
```python
class Solution(object):
    def distinctSubseqII(self, S):
        """
        :type S: str
        :rtype: int
        """
        last_index = dict()
        counter = [0 for i in range(len(S))]# 记录以i 为结尾的，新增的不重复的非空字串个数
        MAX_NUM = 10**9+7
        sum_cnt = 0
        for rhs, c in enumerate(S):
            if c not in last_index:
                counter[rhs] += 1
            lhs = last_index.get(c, 0)
            for idx in range(lhs, rhs): # 由于S[lhs] 和 S[rhs] 相同 0~S[rhs-1]子序列加s[rhs] 的子序列必然与已有序列重复。所以只累加 lhs~rhs的的数量
                counter[rhs] = (counter[rhs]+counter[idx]) % MAX_NUM
            last_index[c] = rhs
            sum_cnt = (sum_cnt + counter[rhs]) % MAX_NUM
        return sum_cnt
```


方法二
### 代码

![image.png](https://pic.leetcode-cn.com/2f7a3355280a9e115869b9db13b96db22bbd02ab168ed676506f5a73144ae8b6-image.png)


```python
class Solution(object):
    def distinctSubseqII(self, S):
        size_s = len(S)
        dp = [0 for _ in range(size_s+1)]
        dp[0] = 1
        last = {}
        MAX_NUM = 10**9+7
        for i, x in enumerate(S):
            pre_si_sum = dp[last[x]] if x in last else 0 # 
            dp[i+1] = (2*dp[i]-pre_si_sum) % MAX_NUM # dp从1开始记录，S从0开始。
            last[x] = i # 记录前一个同字符在S的位置。该idx 是是 dp 中的idex-1
        return (dp[size_s]-1) % (MAX_NUM)
```