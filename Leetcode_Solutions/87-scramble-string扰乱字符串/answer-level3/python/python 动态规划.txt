## 解题思路

dp[i][j][length] 代表 s1 从下标 i 开始，s2 从下标 j 开始，长度为 length 的两个字串是否可以通过扰乱得到，如果可以，值为 True
例如： 
```python
s1 = 'abcde'
s2 = 'deabc'
```
dp[0][2][3] 的值为 True。指的是 s1 的前三个字符扰乱后可以变成 s2 的后三个字符。
### 初始化
所有 length 为 1 的情况必须是那个字符相等。
所以初始化：dp 先初始化为全 False，然后两两比较 s1 s2 的每个字符，相等的赋值为 True。
```python
dp = [[None for _ in range(l)] for _ in range(l)]
for i in range(l):
    for j in range(l):
        dp[i][j] = [False] * (min(l-i, l-j)+1) 
for i in range(l):
    for j in range(l):
        dp[i][j][1] = s1[i] == s2[j]
```

### 状态转移方程
对与两个字符串是否可以通过扰乱互相转换，我们可以一层一层的看，最高层就是整个字符串，最底层是字符。每一层都可以把这个串拆成两个子串。

对于每一层可以归纳为两种情况：一是当前层的两个子串经过交换，第二种当前层未经过交换。

对于这每一种情况，都要检查每一种子串划分的方法




## 代码

```python
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        l = len(s1)
        if l != len(s2): return False
        dp = [[None for _ in range(l)] for _ in range(l)]
        for i in range(l):
            for j in range(l):
                dp[i][j] = [False] * (min(l-i, l-j)+1)
        for i in range(l):
            for j in range(l):
                dp[i][j][1] = s1[i] == s2[j]
        for length in range(2, l+1):
            for i in range(l-length+1):
                for j in range(l-length+1):
                    for sep in range(1, length): # 检查每一种子串划分的方法， sep 是分割的点
                        if dp[i][j][sep] and dp[i+sep][j+sep][length - sep]:      # 当前层两个子串未经过交换的情况
                            dp[i][j][length] = True
                            break
                        if dp[i][j+length-sep][sep] and dp[i+sep][j][length-sep]: # 当前层的两个子串经过交换的情况
                            dp[i][j][length] = True
                            break
        return dp[0][0][l]
```

欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)