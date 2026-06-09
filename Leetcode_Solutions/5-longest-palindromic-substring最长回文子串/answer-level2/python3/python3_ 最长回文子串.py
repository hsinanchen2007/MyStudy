```python
def longestPalindrome(s):
    def help(s, left, right):
        """
            1. 针对s, 从left向左扩散, right向右扩散, 得到当前最大的回文子串
            2. 返回其子串的长度
        """
        N = len(s)
        while left >= 0 and right < N and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1
    
    if not s:
        return ""
    start, end = 0, 0
    for i in range(len(s)):
        # 回文子串存在两种情况: aba, aa
        len1, len2 = help(s, i, i), help(s, i, i + 1)
        len0 = max(len1, len2)
        if len0 > end - start:
            # 定位到当前子串的start, end索引
            start = i - (len0 - 1) // 2
            end = i + len0 // 2
    return s[start:end + 1]

print(longestPalindrome("babad"))
print(longestPalindrome("cbbd"))
```