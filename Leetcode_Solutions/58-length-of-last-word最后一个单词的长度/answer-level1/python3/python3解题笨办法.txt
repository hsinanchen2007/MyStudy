class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if len(s) != 0:
            s_list = s.split(' ')
            
            while '' in s_list:
                s_list.remove('')
            
            if len(s_list) != 0:
                return len(s_list[-1])
            else:
                return 0
        else:
            return 0
            