```python
def numDecodings(s):
    """
        1. dp问题: dp[i] = dp[i - 1] + dp[i-2]
        2. 此题有点难, 答案来自:
        https://leetcode.com/problems/decode-ways/discuss/240637/Python-solution
    """
    def help(i):
        if i in dic:
            return dic[i]
        if i >= len(s):
            return 1
        res = 0
        # 第一位合法的情况(0不合法)
        if 1 <= int(s[i]) <= 9:
            res += help(i + 1)
        # 前两位合法的情况
        if 10 <= int(s[i:i+2]) <= 26:
            res += help(i + 2)
        # 之所以需要dic, 是因为i + 1, i + 2的两次递归调用, 会产生重复计算
        dic[i] = res
        return res
    dic = {}
    return help(0) if s else 0

print(numDecodings("12"))
print(numDecodings("226"))
print(numDecodings("4123718931"))
```