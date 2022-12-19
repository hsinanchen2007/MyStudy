class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        # 只保留字母和数字
        s = filter(str.isalnum, s)
        s = "".join(s)
        new_s = s[::-1]
        
        return True if new_s==s else False