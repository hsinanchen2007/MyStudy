"""
    事实上，只需使用恒定的空间，我们就可以在 O(n2) 的时间内解决这个问题。
    我们观察到回文中心的两侧互为镜像。因此，回文可以从它的中心展开，
    并且只有 2n -1 个这样的中心。    
    你可能会问，为什么会是 2n -1 个，而不是 n 个中心？
    原因在于所含字母数为偶数的回文的中心可以处于两字母之间（例如 "abba" 的中心在两个 "b" 之间）。
    """

    def longestPalindrome2(self, s):
        """
        :param s:
        :return:
        """
        start, end = 0, 0
        for i in range(len(s)):
            len1 = self.expandAroundCenter(s, i, i)
            len2 = self.expandAroundCenter(s, i, i + 1)
            lenSubstring = max(len1, len2)
            if lenSubstring > (end - start):
                start = i - (lenSubstring - 1) // 2
                end = i + lenSubstring // 2
        return s[start: end + 1]

    def expandAroundCenter(self, s, left, right):
        L, R = left, right
        while (L >= 0 and R < len(s) and s[L] == s[R]):
            L -= 1
            R += 1
        return R - L - 1