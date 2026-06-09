from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        c1 = Counter(s)
        c2 = Counter(t)
        if c1 == c2:
            return True
        else:
            return False