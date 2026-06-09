class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        def not_empty(s):
            return s and s.split()
        
        if not s: # ''情况
            return 0
        if ' ' in s:  # ' ' 或者 'a  b  ' 或者 'a b c' 
            a = s.split(' ')
            b = list(filter(not_empty, a))  # 第二种情况就会还存在空格，去掉 
            if b:  # 第三种情况
                return len(b[-1])
            else:  # 第一种情况 
                return 0
        else:  # 'a' 情况
            return len(s)