class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        sub_str = ''
        idx_map = {}
        i, j = 0, 0
        for idx, letter in enumerate(s):
            if letter in s[i:j]:
                max_length = max(max_length, j - i)
                i = idx_map[letter] + 1                 
            
            j += 1
            idx_map[letter] = idx

        max_length = max(max_length, j - i)
        return max_length
