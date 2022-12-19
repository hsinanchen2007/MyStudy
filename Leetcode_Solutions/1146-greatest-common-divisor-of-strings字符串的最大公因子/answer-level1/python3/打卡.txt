class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        l1,l2 = len(str1),len(str2)
        if str1 + str2 != str2 + str1:
            return("")
        if l1 < l2:
            l1,l2,str1,str2=l2,l1,str2,str1
        while l1 % l2 != 0:
            t = l1//l2
            l1 = l1 - l2*t
            str1 = str1[:l1]
            l1,l2,str1,str2=l2,l1,str2,str1
        t = l1 // l2
        return(str2)