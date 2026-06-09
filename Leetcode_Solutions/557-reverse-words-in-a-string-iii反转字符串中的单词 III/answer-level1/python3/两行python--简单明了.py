class Solution:
    def reverseWords(self, s: str) -> str:
        if not s:
            return s
        tmp=[list(reversed(x)) for x in s.split(' ')]
        s=' '.join([''.join(x) for x in tmp])
        return s