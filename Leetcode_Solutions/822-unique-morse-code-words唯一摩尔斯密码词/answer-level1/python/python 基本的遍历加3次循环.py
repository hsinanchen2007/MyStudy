class Solution(object):
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
      
        word = ["a","b","c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p",                               "q","r", "s", "t", "u", "v", "w", "x", "y", "z"]
        en = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",                     ".-..", "--", "-.", "---", ".--.",
                "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
        dict1 = {}
        for i in range(len(word)):
            dict1[word[i]] = en[i]
        u=[]
        for j in words:
            l=""
            for k in j:
                l=l+dict1[k]
            u.append(l)
        a=set(u)
        return len(a)