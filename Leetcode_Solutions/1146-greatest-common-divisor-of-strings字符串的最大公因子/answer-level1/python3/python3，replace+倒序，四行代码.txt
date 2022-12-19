# replace+倒序四行代码

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        for i in range(len(str1), -1, -1):
            if str1.replace(str1[:i], "") == "" and str2.replace(str1[:i], "") == "":
                return str2[:i]
        return ""

时间复杂度O(s)，空间O(1)