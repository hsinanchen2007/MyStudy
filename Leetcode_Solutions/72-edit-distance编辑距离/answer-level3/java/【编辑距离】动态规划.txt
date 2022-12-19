### 解题思路

题目意思是给定两个单词`word1`和`word2`，不断地进行操作，使得两个单词变成一样的**最小操作数**，其中每次操作可以对**其中一个单词**进行如下三种操作：
- 插入一个字符
- 删除一个字符
- 替换一个字符

这三种操作对`word1`和`word2`都能进行，所以一共有`6`种操作：
1. 在`word1`中插入一个字符
2. 删除`word1`中的一个字符
3. 替换`word1`中的一个字符 
4. 在`word2`中插入一个字符
5. 删除`word2`中的一个字符
6. 替换`word2`中的一个字符

首先，`操作3`和`操作6`是显然等价的，因为执行这两个操作的前置都是`word1`和`word2`只有一个字符不一样，那无论替换`word1`还是`word2`，都是`1`步就能到位。例如：
```
word1 = "abc"    word2 = "abd"
无论是将 word1 中的的 c 换成 d， 还是将 word2 中的 d 换成 c，都能使得两个字符串相同
```
然后，`操作1`和`操作4`也是等价的，因为执行这两个操作的前置都是`word2`比`word1`多一个字符，记为`c`，要使两个字符串相同，那么向`word1`插入一个`c`或者删掉`word2`中多的那个`c`都能满足条件。例如:
```
word1 = "abc"    word2 = "abcd"
无论是在 word1 中插入一个 d 还是删除 word2 中的 d 都能使得两个字符串相同
```
同理`操作2`和`操作5`是等价的。

综上所述，这 6 种操作实际上就是 3 种操作:
1. 在`word1`中插入一个字符
2. 在`word2`中插入一个字符
3. 替换`word1`中的一个字符 

那现在就好办了，对于给定的两个字符串`word1`和`word2`，设 `dp[i][j]` 为 `word1[0,...,i]`转换到`word2[0,...,j]`的最小操作数，根据上述的操作，显然有：

$
dp[i][j]  \ = \left\{
\begin{aligned}
dp[i - 1][j - 1]，&  {word1[i] == word2[j]} \\
1 + min(dp[i - i][j - 1],\  dp[i - 1][j], \ dp[i][j - 1])，&  {word1[i]  ≠≠ word2[j]}  \\
\end{aligned}
\right.
$  

- `dp[i - 1][j - 1]`：`word1`和`word2`仅有1个字符不一样，执行`操作3`就可以了
- `dp[i - 1][j]`：`word1`比`word2`少1个字符，执行`操作1`就行了
- `dp[i][j - 1]`：`word2`比`word1`少1个字符，执行`操作2`就行了



### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {

        int len1 = word1.length();
        int len2 = word2.length();

        int[][] dp = new int[len1 + 1][len2 + 1];

        // 如果其中一个字符串为空串，那么操作数就为另外一个字符串的长度
        for (int i = 0; i <= len1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= len2; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                // 如果两个字符串最后一个字母相同，那么把两个字符串最后的一个字母都去掉，最小操作数的结果不变
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }

        return dp[len1][len2];
    }

    // 三个数的最小值
    private int min(int a, int b, int c) {
        return Math.min(a, Math.min(b, c));
    }
}
```
对于上述状态转移方程，我们注意到每次状态转移的时候其实**只用到两行**数据，在**行维度上**是**滚动更新**的，那么我们可以将 dp 数组优化成 `2 * word2.length()`的二维数组。其实还可以进行优化，用1个一维数组和1个变量就可以了：
$
dp[j]  \ = \left\{
\begin{aligned}
prev，&  {word1[i] == word2[j]} \\
1 + min(dp[j - 1], \ dp[j],\  prev)，&  {word1[i]  ≠≠ word2[j]}  \\
\end{aligned}
\right.
$ 
其中 prev 可以看成是之前的 `dp[i - 1][j − 1]`。