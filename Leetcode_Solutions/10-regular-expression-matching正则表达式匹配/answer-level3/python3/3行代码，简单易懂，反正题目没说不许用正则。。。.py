import re
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        a = re.findall(p,s)
        return s in a

直接用正则来匹配，我不管，反正题目没说不许用