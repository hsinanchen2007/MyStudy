1. class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        dd = dict(collections.Counter(s))
        num = 0
        for v in dd.values():
            if v % 2 == 1: 
                num +=1
        return num <= 1