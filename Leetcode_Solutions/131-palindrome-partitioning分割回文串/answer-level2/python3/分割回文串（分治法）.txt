### 分治法
1. 对于字符串“s0s1...sn”，先计算出字符串“sn”,"sn-1sn",...,"s1s2...sn"这些字符串的所有分割方法，并将结果保存下来；
2. 此时计算“s0s1...sn”的所有分割方法：遍历整个字符串，若“s0s1...sk”为回文子串，则其分割方法包括"s0s1...sk"+"sk+1sk+2...sn"的所有分割方法；
3. 通过1，2步的归纳推导，可以计算出最终字符串s的所有分割方法；

#### 优化技巧
通过阅读[@windliang](/u/windliang/)的题解，可以通过一个dp的二维列表（如dp[i][j]表示s[i,j+1]是否为回文子串，这里是基于[动态规划](https://leetcode-cn.com/problems/palindrome-partitioning/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-3-7/)来求解的）来进一步降低时间复杂度；


### 代码

```python3
class Solution:
    """
    对于字符串“s0s1s2...sn”而言，先计算字符串[“s0”,“s0s1”,"s0s1s2",...,"s0s1s2...sn-1"]的分割方案，然后从“sn”开始遍历整个字符串，若“sksk+1...sn”是回文串，则“s0s1...sk-1”的分割方案后+“sksk+1...sn”是部分分割方案；继续遍历从而找到所有的“s0s1s2...sn”的分割方案
    """
    def isPalindromic(self, s):
        """
        判断字符串s是否为回文串
        """
        if len(s) == 1:
            return True
        
        numsOfChar = len(s)
        for i in range(numsOfChar//2):
            if s[i] != s[numsOfChar-i-1]:
                return False
        return True

    def calculation(self, s, partition_ways, numsOfChar):
        """
        计算字符串s的所有分割方法，并将其结果保存在字典partition_ways中
        """
        if numsOfChar == 1:
            # 长度为1的字符串其回文子串只有其本身
            partition_ways[numsOfChar] = [[s]]
        else:
            partition_ways[numsOfChar] = []
            for i in range(numsOfChar):
                if self.isPalindromic(s[:i+1]):
                    # 若s[:i+1]是回文子串，则s[:i+1]与s[i+1:]的任一分割方案合并均为s的一种分割方法；
                    # 特殊情况s本向是回文子串时需要另外考虑，如下代码；
                    if numsOfChar-i-1 > 0:
                        partition_ways[numsOfChar].extend([ [s[:i+1]]+tmp for tmp in partition_ways[numsOfChar-i-1] ])
                    else:
                        partition_ways[numsOfChar].extend([[s]])

    def partition(self, s: str) -> List[List[str]]:
        # 检查输入参数的有效性
        if s.strip() == '':
            return []
        
        # 用字典存储不同长度字符串的所有分割方案
        partition_ways = dict()

        numsOfChar = len(s)
        for i in range(numsOfChar):
            # 字符串s从后往前遍历，计算不同字符串长度的分割方法，并将结果保存在字典中
            self.calculation(s[numsOfChar-i-1:], partition_ways, i+1)

        return partition_ways[numsOfChar]
```