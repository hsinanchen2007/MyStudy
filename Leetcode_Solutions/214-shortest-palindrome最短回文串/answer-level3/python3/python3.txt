    def shortestPalindrome(self, s: str) -> str:
        max_index = 0
        s_size= len(s)
        for i in range(s_size):
            if s[:i+1] == s[i-s_size::-1]:
                max_index = max(max_index, i)
        return s[:max_index:-1] + s