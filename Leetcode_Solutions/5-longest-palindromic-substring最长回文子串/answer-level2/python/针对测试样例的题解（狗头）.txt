class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        left,right = 0,0 #左右指针
        s_len,temp_len = 0,0 #最长及临时回文子串长度
        count = 1 #连续字符个数
        str = ''
        if s:str = s[0]
        lenth = len(s)
        flag = 1
        for i in range(lenth):
            if i>0 and s[i] == s[i-1]:
                flag = 0
                count += 1
                if count > s_len:
                    s_len = count
                    str = s[i-count+1:i+1]
            else:
                flag = 1
                count = 1
            left = i - 1
            right = i + 1
            if left<0 or right>lenth-1 : continue
            while s[left] == s[right]:
                temp_len = right - left + 1
                if temp_len > s_len:
                    s_len = temp_len
                    str = s[left:right+1]
                left = left-1
                right = right+1
                if left<0 or right>lenth-1 :break
            
            if flag == 0:
                left = i - 1
                right = i
                if left<0 or right>lenth-1 : continue
                while s[left] == s[right]:
                    temp_len = right - left + 1
                    if temp_len > s_len:
                        s_len = temp_len
                        str = s[left:right+1]
                    left = left-1
                    right = right+1
                    if left<0 or right>lenth-1 :break
            
        return str