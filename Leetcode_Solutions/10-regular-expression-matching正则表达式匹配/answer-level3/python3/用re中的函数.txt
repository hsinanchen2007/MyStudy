class Solution:
    #自己尝试着写的，竟然验证通过了，re.match应该是从开始对字符串的最大匹配
    def isMatch(self, s: str, p: str) -> bool:
        lens=len(s)
        if re.match(p,s):
            #开始匹配成功 因为没有大写字母，所以函数不用填标志位
            s=re.match(p,s).span()# match应该是从开始对字符串的最大匹配
            a=list(s)
            print (s)
            if a[1]<lens:return False
            else:return True