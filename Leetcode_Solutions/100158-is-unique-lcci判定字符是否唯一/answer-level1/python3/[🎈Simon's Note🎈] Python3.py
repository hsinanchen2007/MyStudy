class Solution:
    def isUnique(self, astr: str) -> bool:
        from collections import Counter
        c=Counter(astr)
        for key in c:
            if c[key]!=1:
                return False
        return True