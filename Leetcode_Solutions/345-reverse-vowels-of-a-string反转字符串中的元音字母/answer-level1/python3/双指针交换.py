class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        l = ["a", "A", "e", "E", "i", "I", "o", "O", "u", "U"]
        str = list(s)
        i, j = 0, len(s)-1
        while i < j:
            while i < j and str[i] not in l:
                i+=1
            while i < j and str[j] not in l:
                j-=1
            str[i], str[j] = str[j], str[i]
            i+=1
            j-=1
        return "".join(str)