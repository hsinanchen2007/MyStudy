`
class Solution(object):
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        row = 1
        tmp = 0
        for c in S:
            if tmp + widths[ord(c) - ord('a')] > 100:
                row += 1
                tmp = widths[ord(c) - ord('a')]
            else:
                tmp += widths[ord(c) - ord('a')]
        return [row, tmp]
`

继续为没有Python答案的简单题做完善
狗尾续貂