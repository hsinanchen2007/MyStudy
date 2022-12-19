class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if strs == "":
            return ""
        elif strs == []:
            return ""
        else:
            n = len(strs)
            first = strs[0]
            if n == 1:
                return first
            else:
                for item in strs:
                    if item == "":
                        return ""
                for m in range(len(first)):
                    for i in range(1,n):
                        if m >= len(strs[i]):
                            return first[:m]
                        elif first[m] != strs[i][m]:
                            if m == 0:
                                return "" 
                            else:
                                return first[:m]
                return first
