中心扩展法参考官方解释，下面主要是python3代码，里面有注释，不清楚的地发欢迎交流。

def expandAroundCenter(s, left, right):
    L = left
    R = right
    while L >= 0 and R < len(s) and s[L] == s[R]:
        L -= 1
        R += 1

    return R - L - 1


class Solution:
    def longestPalindrome(self, s: str) -> str:
        if s is None or len(s) < 1:
            return ''

        start = 0
        end = 0
        for i in range(len(s)):
            # 探索回文为奇数个的情况
            len1 = expandAroundCenter(s, i, i)
            # 探索回文为偶数个的情况
            len2 = expandAroundCenter(s, i, i + 1)
            leng = max(len1, len2)
            # end - start 表示之前最长的回文长度
            if leng > end - start:
                # 如果新的回文长度大于原来的长度，则更新回文的开始和结束位置
                start = i - (leng - 1) // 2
                end = i + leng // 2

        return s[start: end + 1]