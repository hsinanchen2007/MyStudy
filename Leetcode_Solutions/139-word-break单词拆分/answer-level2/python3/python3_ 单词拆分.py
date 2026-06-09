```python
def wordBreak(s, wordDict):
    # 暴力解法(超时--问题在于重复计算)
    r = False
    def help(s, d):
        nonlocal r
        if r or not s:
            r = True
            return True
        for w in d:
            if w == s[0:len(w)]:
                help(s[len(w):], d)

    help(s, wordDict)
    return r

def wordBreak1(s, wordDict):
    """
        1. 此题有点难度, 答案来自: 
        https://leetcode.com/problems/word-break/discuss/43788/4-lines-in-Python
        2. dp问题: 针对s, dp[0~i] = dp[0~j] + dp[j~i], i = len(s)
        3. 我们将dp[0~j]存储到ok数组中, 避免重复判断.
    """
    ok = [True]
    for i in range(1, len(s) + 1):
        ok.append(any(ok[j] and s[j:i] in wordDict for j in range(i)))
    return ok[-1]

print(wordBreak("leetcode", ["leet", "code"]))
print(wordBreak("applepenapple", ["apple", "pen"]))
print(wordBreak("catsandog", ["cats", "dog", "sand"]))
print(wordBreak("cars", ["car", "ca", "rs"]))
print(wordBreak1("leetcode", ["leet", "code"]))
print(wordBreak1("applepenapple", ["apple", "pen"]))
print(wordBreak1("catsandog", ["cats", "dog", "sand"]))
print(wordBreak1("cars", ["car", "ca", "rs"]))
```