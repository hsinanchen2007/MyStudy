class Solution:

    def reverseVowels(self, s: str) -> str:

        if len(s) <= 1:
            return s
        seed = "aeiouAEIOU"
        s = list(s)
        l = 0
        r = len(s)-1
        
        while l < r:
            if s[l] not in seed:
                l += 1
            if s[r] not in seed:
                r -= 1
                
            if s[l] in seed and s[r] in seed:
                s[l],s[r] = s[r],s[l]
                l += 1
                r -= 1
                
        return "".join(s)