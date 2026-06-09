`class Solution():
    def strStr(self, haystack, needle):
        if not haystack and not needle:
            return 0
        elif not haystack:
            return -1
        elif not needle:
            return 0
        elif haystack == needle:
            return 0
        else:
            num1 = len(haystack)
            num2 = len(needle)
            if num1<num2:
                return -1
            else:
                for i in range(num1-num2):
                    if haystack[i] == needle[0] and haystack[i:(i+num2):] == needle:
                        return i
                return -1`

