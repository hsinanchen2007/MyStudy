思路：
先通过split（）将整个字符串以空格为界拆成几个独立单词，返回字符串列表，之后直接通过len（）求出最后一个单词长度:
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        
        w=s.split( )
        if len(w)==0:
            return 0
        else:
            c=len(w[-1])
            return c