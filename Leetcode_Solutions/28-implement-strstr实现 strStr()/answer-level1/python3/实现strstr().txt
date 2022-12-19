class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle == '':
            return 0
        
        l_hay = len(haystack)
        l_nee = len(needle)
        
        if l_hay < l_nee:
            return -1
        
        for i in range(0, l_hay - l_nee + 1):
            for j in range(0, l_nee): # 循环实现字符串比较
                if haystack[i+j] != needle[j]:
                    break
            else:
                return i # 此处用到了python语言特性, for如果没有被break，可以执行else语句，否则不执行。
            #if haystack[i:i+l_nee] == needle: #直接字符串比较
            #    return i
        return -1