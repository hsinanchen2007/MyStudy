class Solution:
    def strStr(self, haystack: str, needle: str) -> int:

        base = 16 # mul. base
        modulo = 97 # mod
        n_len = len(needle) # n 
        hs_len = len(haystack) # m 
        if n_len == 0: return 0
        if hs_len < n_len: return -1
        n_hash = 0
        hs_hash = 0
        highest_multiplier = base ** (n_len-1)

        for i in range(n_len):
            n_hash = (n_hash * base + ord(needle[i])) % modulo
            hs_hash = (hs_hash * base + ord(haystack[i])) % modulo
        
        for i in range(hs_len - n_len +1):
            if hs_hash == n_hash and haystack[i:i+n_len] == needle:
                return i
            
            if i < hs_len - n_len:
                # rolling hash
                hs_hash -= ord(haystack[i]) * highest_multiplier 
                hs_hash *= base # all chars shift to left by 1
                hs_hash = (hs_hash + ord(haystack[i+n_len])) % modulo
        return -1
