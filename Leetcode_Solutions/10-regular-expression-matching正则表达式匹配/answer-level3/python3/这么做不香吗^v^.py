class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        a = re.match(p,s)
        if a == None:
            return False
        elif a.group() == s:
            return True
        else:
            return False