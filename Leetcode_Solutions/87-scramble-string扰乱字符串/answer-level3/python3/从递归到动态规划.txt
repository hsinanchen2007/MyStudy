
> 声明：这篇题解是在以下两位大佬的题解的基础上整理出来的。  

[力扣（LeetCode）powcai](https://leetcode-cn.com/problems/scramble-string/solution/di-gui-by-powcai/)  
[力扣（LeetCode）jerry_njuT_1](https://leetcode-cn.com/problems/scramble-string/solution/miao-dong-de-qu-jian-xing-dpsi-lu-by-sha-yu-la-jia/)  


> 方法一、递归  

S 和 T  如果是 扰动 的话，那么必然存在一个在 S 上的长度 l1，将 S 分成 S1 和 S2 两段，同样 T 上也有一个长度l2，把 T 分为 T1 和 T2。  
1、那么要么 S1 和 T1 是 **扰动** 的且 S2 和 T2 是 **扰动** 的，即字符串未交换。  
2、要么 S1 和 T2 是 **扰动** 的且 S2 和 T1 是 **扰动** 的，即字符串交换了。  
就拿题目中的例子 rgeat 和 great 来说，rgeat 可分成 rg 和 eat 两段， great 可分成 gr 和 eat 两段，rg 和gr是扰动的， eat和eat也是扰动的。  

*代码*  
```python
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):  return False
        if s1 == s2:  return True
        if sorted(s1) != sorted(s2):  return False
        for i in range(1, len(s1)):
            S1, S2 = s1[:i], s1[i:]
            T1, T2 = s2[:i], s2[i:]
            if self.isScramble(S1, T1) and self.isScramble(S2, T2):  return True
            T1, T2 = s2[:-i],s2[-i:]  # S1、S2不变，更新T1、T2
            if self.isScramble(S1, T2) and self.isScramble(S2, T1):  return True
        return False
```

> 方法二、动态规划

*直觉*  
给定两个字符串 $T$ 和 $S$，假设 $T$ 是由 $S$ 变换而来。  

- 如果 $T$ 和 $S$ 长度不一样，必定不能变来。  
- 如果长度一样，顶层字符串 $S$ 能够划分为 $S_1$ 和 $S_2$，同理，字符串$T$也可以划分为​ $T_1$ 和 $T_2$。
  - 情况一：没交换，$S_1 = T_1$  且 $S_2 = T_2$。  
  - 情况二：交换了，$S_1 = T_2$  且 $S_2 = T_1$。  
- 子问题就是分别讨论两种情况，$T_1$ 是否由 $S_1$ 变来且$T_2$ 是否由 $S_2$ 变来。或者，$T_1$ 是否由 $S_2$ 变来且$T_2$是否由$S_1$ 变来。  

*状态转移方程*  
$dp[i][j][k][h]$ 表示 $T[k...h]$ 是否由 $S[i...j]$ 变来。由于变换必须长度一样，所以上述变换关系可以从四维简化为三维，即，$dp[i][j][len]$ 表示从字符串 $S$ 中 $i$ 开始长度为 $len$ 的字符串是否能变换为从字符串 $T$ 中 $j$ 开始长度为 $len$ 的字符串，因此转换方程如下：  
$$
dp[i][j][k] = dp[j][j][w]\ and\ dp[i+w][j+w][k-w] (1 \leq w \leq k-1 )\ \ OR\ \  \\
dp[i][j][k] = dp[j][j+k-w][w]\ and\ dp[i+w][j][k-w] (1 \leq w \leq k-1 )
$$

解释：枚举 $S_1$长度 $w$（从$1～k-1$，因为要划分），$f[i][j][w]$ 表示 $S_1$ 能变成 $T_1$，$f[i+w][j+w][k-w]$表示 $S_2$ 可以变成 $T_1$。而 $f[j][j+k-w][w]$ 表示 $S_1$ 能变成 $T_2$，$f[i+w][j][k-w]$ 表示 $S_2$ 能变成 $T_1$。  
  

*终止条件*  
$dp[i][j][len]$ 表示字符串$S$从$i$开始长度为$len$的子串能否变换成字符串$T$从$j$开始长度为$len$的子串，所以终止条件为 $dp[0][0][n] = True$，其中 $n$ 为输入字符串的长度。  

*算法*  

- 特判 `S` 和 `T` 长度不一样的情况  
- 初始化三维数组 `dp`
- 初始化单个字符的情况。如果把 `dp` 三维数组想象成一个立方体，初始化单个字符的操作，就是设置`w=1` 然后初始化 `i`和`j` 组成的平面，也就是立方体的最底面。
- 开始划分区间，区间长度为n，也就是划分为 `s1[:k]` 和 `s1[k:]`，枚举区间长度2～n（n为字符串长度）  
  - 枚举S中的起点位置 `i`，也就是在 `S` 中枚举i的位置，因为后面会出现 `i+w` 的情况，而 `w` 最大就是 `k`，就会有 `i+k` 的情况，所以 `i` 的取值范围就是 `0~n-k`。
  - 枚举 `T` 中的起点位置 `j`，同上，`j` 的取值范围就是 `0~n-k`。
  - 枚举划分位置 `w`，范围是 `1~k`，然后进行两种情况的判定。
    - 第一种情况：`S1->T1, S2->T2`，当前层的两个子串未经过交换的情况。
    - 第二种情况：`S1->T2, S2->T1`，当前层的两个子串经过交换的情况。
- 返回 `dp[0][0][n]`


*两种情况的判定的代码*

![Snipaste_2020-03-23_14-04-54.png](https://pic.leetcode-cn.com/bcea13fe0b320f3670ad951ac2d1f11cf3ccbe9580940c7ebe1565e9efed76fb-Snipaste_2020-03-23_14-04-54.png)


*图解*  

![Snipaste_2020-03-23_12-32-04.png](https://pic.leetcode-cn.com/4c57de088b00b87621bd2c32d57120203c4611a1a1c6889a664d9545cf1ae2db-Snipaste_2020-03-23_12-32-04.png)


从这张图就可以知道动态规划的**自底向上**特性了。


*代码*  

```python
class Solution:
    def isScramble(self, s1, s2):
        S_len = len(s1)
        T_len = len(s2)
        
        # 一些特判
        if S_len != T_len:  return False
        if s1 == s2:  return True
        if sorted(s1) != sorted(s2):  return False
        
        # 初始化 dp 三维数组dp[i][j][k]
        # i为0~S_len共S_len+1个， j为0~S_len-1共S_len个， k为1~S_len+1共S_len个
        dp = [ [ [False]*(S_len+1) for _ in range(S_len) ] for _ in range(S_len) ]

        # 初始化单个字符的情况
        for i in range(S_len):
            for j in range(T_len):
                dp[i][j][1] = s1[i] == s2[j]  
        
        # 前面排除了s1和s2为单个字符的情况，那么我们就要划分区间了，k从2到S_len，也就是划分为s1[:k]和s1[k:]
        for k in range(2, S_len + 1):  # 枚举区间长度2～S_len
            # 枚举S中的起点位置 i，也就是在s1中枚举i的位置，因为后面会出现i+w的情况，而w最大就是k，就会有i+k的情况，所以i的取值范围就是0~S_len-k。
            for i in range(S_len - k + 1):
                # 枚举T中的起点位置 j
                for j in range(T_len - k + 1):
                    # 枚举划分位置 w
                    for w in range(1, k):
                        # 第一种情况：S1->T1,S2->T2
                        if dp[i][j][w] and dp[i + w][j + w][k - w]:
                            dp[i][j][k] = True
                            break
                        # 第二种情况：S1->T2,S2->T1
                        # S1起点i，T2起点j + 前面那段长度 k-w，S2起点i+前面长度w，T1起点为j。
                        if dp[i][j + k - w][w] and dp[i + w][j][k - w]:
                            dp[i][j][k] = True
                            break
        return dp[0][0][S_len]
```