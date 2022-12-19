1、首先定义什么是回文数: 即 s == s[::-1]

2、如果已知一个回文数s，那么具有什么性质呢？
    2.1、在s左右两边加相同的字符c，则回文数的长度+2，即csc也为回文数，并且长度为len(s) + 2
    2.2、在其左右两边加不同的字符a、b，则最长回文数的长度不变; 即asb中，只有s部分为回文数;换句话说as或sb中的最长回文数等于s

3、递归方法
  根据上述描述，容易写出来的是递归方法；我们可以把求[0,n-1] (n = len(s)) 区间的最长回文数，通过判定
s[0] 和 s[n - 1]，从而转为求更小区间的最长回文数。 
  ```
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        def backtracking(i, j, s):
            if not (i >= 0 and i < len(s) and j >= 0 and j < len(s)):
                return 0
            elif i == j:
                return 1
            elif i > j:
                return 0
            if s[i] == s[j]:
                return backtracking(i + 1, j - 1, s) + 2
            else:
                return max(backtracking(i + 1, j, s), backtracking(i, j - 1, s)) 
        n = len(s)
        return backtracking(0, n - 1, s)

```
上述递归代码超时(61 / 83)，可转换为非递归代码，转换方法是: 在求[0,n-1]区间的回文数之前,必须求得[1, n - 2]、[0, n -2] 和[1, n - 1]区间的最长回文数，以此类推，即我们需要用一个二维数组存储求[0, n - 1]区间的回文数之前的历史信息。


