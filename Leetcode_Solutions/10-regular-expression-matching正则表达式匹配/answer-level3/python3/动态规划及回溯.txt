动态规划添加了行间注释, 状态矩阵:
![isMatch.png](https://pic.leetcode-cn.com/ba67899675bcd162f57a6cfa2a100b28df74c4fd6765af435a9390a7e32f61de-isMatch.png)
```
class Solution:
    '''
    给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。
        '.' 匹配任意单个字符。
        '*' 匹配零个或多个前面的元素。
    匹配应该覆盖整个字符串 (s) ，而不是部分字符串。
    s 可能为空，且只包含从 a-z 的小写字母。
    p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *

    参考: https://blog.csdn.net/hk2291976/article/details/51165010
    '''

    def isMatch(self, s: str, p: str) -> bool:
        '''
        p.charAt(j) == s.charAt(i) : dp[i][j] = dp[i-1][j-1]
        If p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1];
        If p.charAt(j) == '*': here are two sub conditions:
        //in this case, a* only counts as empty, otherwise is not match
        - if p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2]
        - if p.charAt(j-1) == s.charAt(i) or p.charAt(i-1) == '.':
            dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a
            dp[i][j] = dp[i][j-1]   // in this case, a* counts as single a
            dp[i][j] = dp[i][j-2]   // in this case, a* counts as empty

        思路: 动态规划, 沿着匹配串和字符串构成矩阵的对角线传递状态
        1. 状态矩阵的首行与首列对应于空字符与空匹配符
        2. 对角线意味着匹配串是否匹配对应的字符串
        '''
        ns = len(s)
        np = len(p)

        dp = [[False] * (np + 1) for _ in range(ns + 1)]
        dp[0][0] = True
        # 匹配空字符串的情况, 匹配串为空时已经为False, 不再更新
        for i in range(np):
            # 根据规则, *前必存在一个字符, 则当前为*时, 其状态与前2的状态一致
            if p[i] == '*' and dp[0][i - 1]:
                dp[0][i + 1] = True
        # 更新状态矩阵
        for i in range(1, ns + 1):
            for j in range(1, np + 1):
                # i,j是矩阵的行与列, 对应到匹配串和字符串的索引要-1
                # 匹配串与字符串匹配(相等或为.)传递状态
                if p[j - 1] == s[i - 1] or p[j - 1] == '.':
                    dp[i][j] = dp[i - 1][j - 1]
                # 匹配串中 * 字符特殊处理
                elif p[j - 1] == '*':
                    # 根据匹配规则, 比较匹配串*的前一个字符与字符串中前一个字符
                    # 二者不相等时, a*只有作为空字符串时才可能匹配,
                    # 这就是说, 略过前一个字符, *字符对应的状态与字符串中前2个字符的状态一致
                    if p[j - 2] != s[i - 1]:
                        dp[i][j] = dp[i][j - 2]
                    # 二者相等时有三种情况
                    # a*作为: 空字符, 单字符 a, 多字符 aaa...
                    if p[j - 2] == s[i - 1] or p[j - 2] == '.':
                        dp[i][j] = dp[i][j - 2] or dp[i][j - 1] or dp[i - 1][j]
        return dp[ns][np]

    def isMatchBack(self, s: str, p: str) -> bool:
        '''
        回溯算法: 从后往前匹配, 一旦遇到 *，前面必然有个字符
        '''

        def match(ins, inp):
            # 如果inp<0, 说明p已经匹配完了，这时候，如果s匹配完了，说明匹配, 反之, 不匹配
            # 如果ins<0, s已经匹配完, 因为p可能有 * , ins可以先匹配完, 也就是到达-1
            if inp == -1:
                if ins == -1:
                    return True
                return False
            if p[inp] == '*':
                if ins > -1 and (p[inp - 1] == s[ins] or p[inp - 1] == '.'):
                    # 回溯点, 有*时, 匹配s的前一个字符, 前一个(不断往前递归得到)匹配, 返回结果
                    # 若否, 回溯到当前位置, 然后判断a*作为空字符的情况, 获取前2的字符的状态
                    # !! 这不会回溯到原来的位置 return match(ins - 1, inp)
                    if match(ins - 1, inp):
                        return True
                return match(ins, inp - 2)
            if ins > -1 and (p[inp] == s[ins] or p[inp] == '.'):
                return match(ins - 1, inp - 1)
            return False

        return match(len(s) - 1, len(p) - 1)


s = Solution()
# print(s.isMatch('aaabc', 'a*bc'))
print(s.isMatchBack('aaa', 'ab*a*c*a'))

```