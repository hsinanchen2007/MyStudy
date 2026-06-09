### 解题思路
同习题 [面试题19. 正则表达式匹配](https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/gelthin-dp-ti-by-gelthin)

此题是典型的 DP 教科书题，从蛮力递归，到自顶向下带备忘录的递归，再到自底向上的 DP

主要参考 官方题解 以及 高赞题解 [面试题19. 正则表达式匹配](https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/zhu-xing-xiang-xi-jiang-jie-you-qian-ru-shen-by-je/)

官方题解评论有人提到了 “有术无道”。

参见题解的讨论，不考虑 pattern 两个连续的 `**`，这个没有意义，`*` 的前一个字符必须是有效字母字符 or `.`, 如果非要处理的话，可以先预处理 pattern, 把两个连续的 `**` 中的后一个 `*` 给去掉。同时我们也不考虑 pattern 是 `*` 这种。

**令人惊奇的是，这一题 DP 方法居然有两种分割子问题的方式，且这两种都 work, 不知道一般的 DP 是否也可以这样？**

一般的 DP 题目似乎是通常只有一个方向往另一个方向推导，当然如果更改了 `DP[i][j]` 代表的含义，也许也可以换一个方向推导？

1. `(s, p) -> (s[0], p[0]) and (s[1:], p[1:])`  # 官方题解 和 [面试题19. 正则表达式匹配的高赞题解](https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/zhu-xing-xiang-xi-jiang-jie-you-qian-ru-shen-by-je/) 的递归解法
   `DP[i][j]` 代表 `(s[i:], p[j:])` 子问题的解

2. `(s, p) -> (s[-1], p[-1]) and (s[:-1], p[:-1])` # [面试题19. 正则表达式匹配的高赞题解](https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/zhu-xing-xiang-xi-jiang-jie-you-qian-ru-shen-by-je/) 的 DP 解法
   `DP[i][j]` 代表 `(s[:i], p[:j])` 子问题的解

都可以自顶向下（带备忘录）的递归， 也可以自底向上，DP
**有了自顶向下的分解，就一定能写出自底向上的方法，只需要考虑从问题规模最小的地方出发就可以，代码逻辑不用改。**


### 代码
自己写的代码，逻辑的判断有些混乱，容易漏考虑情况，例如，递归何时结束情况考虑不清楚。

官方题解的逻辑很好。不用同时考虑 pattern 和 text 是否结束

+ 首先判断 pattern 是否结束，如果 pattern 结束了，那么 text 也应该结束了，否则返回 False.
+ 如果 pattern 没有结束（这里 text 可以已经结束）
    + 如果pattern 长度至少为 2， 且当前第二个为 '*', 那么就要小心处理，不用（直接砍掉），或者接着用。（这里就不用考虑只用一次，因为 text 可以已经结束）
    + 如果 pattern 长度为 1 or pattern 第二个字符不是 '*', 那么判断当前字符以及后续匹配是否成功。

#### 官方代码可圈可点的地方：
1. `dict()` 往里面加元素，就像 list 一样，不算改动，不用声明 `global`, `nonlocal`
2. `(i,j)` tuple 作为 key, 可以简写为 `memo[i,j]`
3. 巧妙地处理 `.`：`pattern[j] in {text[i], '.'}`
4. `ans = (i == len(text))`

#### 下面是自己写的打了大量补丁，逻辑层次不清晰的丑陋代码
```python3
class Solution(object):
    def isMatch(self, text, pattern):
        # 不考虑两个连续的 **
        # 本题中分割子问题的方式有两种，且这两种都 work， 不知道一般的 DP 是否也是可以这样？:
        # 1. (s, p) -> (s[0], p[0]) and (s[1:], p[1:])  # 官方题解
        #   DP[i][j] 代表 (s[i:], p[j:]) 子问题的解
        # 2. (s, p) -> (s[:-1], p[:-1]) and (s[-1], p[-1]) # 面试题19. 正则表达式匹配-高赞解
        #   DP[i][j] 代表 (s[:i], p[:j]) 子问题的解
        #   都可以自顶向下（带备忘录）， 也可以自底向上，DP

        # 划分方式 1 
        memo = dict() #往里面加元素，不算改动，不用声明 global, nonlocal
        def dp(i, j):
            if (i, j) in memo:
                return memo[(i,j)]  # (i,j) tuple 作为 key, 可以简写为 memo[i,j]
            # DP[i][j] 代表 (s[i:], p[j:]) 子问题的解
            if i > len(text) or j > len(pattern):
                res = False
            elif i == len(text):
                if j == len(pattern):
                    res = True
                elif j+1<len(pattern) and pattern[j+1] == '*': #不加此,"a, ab*" 过不去,以及下面要考虑只用一次
                    res = dp(i, j+2)
                else:
                    res = False
            elif j+1<len(pattern) and pattern[j+1] == '*':
                if pattern[j] in {text[i], '.'}: # a* 可以用上， 例如 aaa,a*a
                    #res = dp(i+1, j) or dp(i+1, j+2) or dp(i, j+2) # 接着用 or 只用一次 or 不用, 漏掉只用一次，aa, a*过不去
                    res = dp(i+1, j) or dp(i, j+2)
                else:
                    res = dp(i, j+2)  # a* 这一段没用上，直接砍掉
            elif j<len(pattern): # p 的第二个元素不是 '*': p只剩下一个元素，or p 剩下多个元素，但第二个元素不是 '*'
                if pattern[j] in {text[i], '.'}:
                    res = dp(i+1, j+1)
                else:
                    res = False
            else:
                res = False       
            memo[(i,j)] = res
            return res

        return dp(0, 0)
```
#### 官方代码 + 注释
``` python3
class Solution(object):
    def isMatch(self, text, pattern):
        memo = dict()
        def dp(i, j):
            if (i, j) in memo:
                return memo[(i,j)]
            if j == len(pattern):
                ans = (i == len(text)) # s[len(s):], p[len(p):] 都为空，相当于全部匹配完了，自然为 True
            else: # 这里 i 可能超标了, 但 j < len(pattern)
                first_match = i < len(text) and pattern[j] in {text[i], '.'}
                if j+1 < len(pattern) and pattern[j+1] == '*':
                    ans = dp(i, j+2) or (first_match and dp(i+1, j)) # 短路表达式，若dp(i, j+2)为True, 后面就不用算，相当于避免了 i 超标的情形啊
                else:
                    ans = first_match and dp(i+1, j+1)
            memo[(i,j)] = ans
            return ans
        
        return dp(0,0)

```
#### 从自顶向下的带备忘的方法 改写成 自底向上的 DP，居然非常自然，几乎没有大的改动。
``` python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # dp[i][j] 代表 (s[i:], p[j:]) 子问题的解
        dp = [[None]*(len(p)+1) for _ in range(len(s)+1)] # dp[-1][-1] = True
        for i in range(len(s), -1, -1):
            for j in range(len(p), -1, -1):  # 官方题解这里 j 从 len(p)-1 开始，因为 j=len(p) 时，可以推出 dp[i][j] = False if i != len(s) else True (p 全部用完了，但是 i 还没匹配完)
                if j == len(p):
                    dp[i][j] = (i==len(s))
                else: 
                    first_match = i<len(s) and p[j] in {s[i], '.'}
                    if j+1 < len(p) and p[j+1] == '*':
                        dp[i][j] = dp[i][j+2] or (first_match and dp[i+1][j])
                    else:
                        dp[i][j] = first_match and dp[i+1][j+1]
        return dp[0][0]
```