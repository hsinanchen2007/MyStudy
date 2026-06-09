首先这个题目格外需要注意 0，例子中并没有体现出来，比如 '06' 并不能解码为 F
* 解法一：回溯
回溯的想法很简单，就是每次选一个长度或两个长度的子串进行解码，如果满足在 1-26 范围内就可行，要注意两位数不能以 0 开头
时间复杂度太高，超时
* 解法二：动态规划
顺序遍历字符串，当前长度 *i* 的子串对应的解码数量可以由前面的状态计算出来，具体如下：
1. 当前数字不为 0 时，一定小于等于 26，可单独作为有效的解码，将这个解码分别添加到前一个数字长度 *i-1* 对应的所有解码序列的最后，就得到了当前数字对应的一部分有效解码
2. 上面只是当前长度子串对应的一部分解码，即单独将当前数字作为一个解码；其实它还可以与前一个数字进行组合如果不以 0 开头并且小于等于 26 那依然是一个有效的解码，同 1 将这个有效的解码分别添加到长度为 *i-2* 对应的所有解码序列的最后，也可形成一部分有效的解码
3. 在这个过程中，其实只需要记录 *i-1* 和 *i-2* 对应的答案，所以并不需要一个数组，可对空间占用进行优化
```python
class Solution:
    # 回溯超时
    def numDecodings(self, s: str) -> int:
        res = 0

        def back_tracking(s: str) -> None:
            nonlocal res
            if not s:
                res += 1
                return
            if int(s[:1]) > 0: back_tracking(s[1:])
            if len(s) > 1 and not s[:2].startswith('0') and 0 < int(s[:2]) <= 26:
                back_tracking(s[2:])

        back_tracking(s)
        return res

    # dp
    def numDecodings1(self, s: str) -> int:
        if not s or s.startswith('0'): return 0
        dp = [0] * len(s)
        dp[0] = 1
        for i in range(1, len(s)):
            if s[i] != '0':
                dp[i] += dp[i - 1]
            if s[i - 1] != '0' and int(s[i - 1:i + 1]) <= 26:
                tmp = dp[i - 2] if i - 2 >= 0 else 1
                dp[i] += tmp
        return dp[-1]

    def numDecodings2(self, s: str) -> int:
        if not s or s.startswith('0'): return 0
        pre_pre = pre = 1
        for i in range(1, len(s)):
            cur = 0
            if s[i] != '0':
                cur += pre
            if s[i - 1] != '0' and int(s[i - 1:i + 1]) <= 26:
                cur += pre_pre
            pre_pre, pre = pre, cur
        return pre
```