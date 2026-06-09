主要是原序列长度n和中心点序列长度2n-1的放大与缩小转换
遍历中心点序列长度m=2n-1，此为放大；当需要原序列时n=(m+1)/2，此为缩小还原。

    def expandFromCenter(self, s, left, right):
        p = left
        q = right
        while p >= 0 and q < len(s) and s[p] == s[q]:
            p = p - 1
            q = q + 1
        return s[(p + 1):q]

    # 中心扩展法 串长n 中心点2n-1个 对于m=2n-1 奇数为单个点为中心 偶数为两个点为中心 n = (m + 1) / 2
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s is None:
            return ''
        n = len(s)
        if n == 0:
            return ''
        m = 2 * n - 1
        result = ''
        for index in range(m):
            if (index % 2) == 0:  # index为偶数则单个点为中心
                tmp = int((index + 1) / 2)
                sub = self.expandFromCenter(s, tmp, tmp)
            else:  # index为奇数则两个点为中心
                tmp1 = int((index - 1 + 1) / 2)
                tmp2 = int((index + 1 + 1) / 2)
                sub = self.expandFromCenter(s, tmp1, tmp2)
            if len(sub) > len(result):
                result = sub
        return result