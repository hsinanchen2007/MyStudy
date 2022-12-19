class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        s='#'+'#'.join(s)+'#'#step1
 
        RL=[0]*len(s) #各种初始化一下，RL是回文半径数组
        MaxRight=0
        Pos=0
        Maxlen=0
 
        for i in range(len(s)):
            if i<MaxRight:#i在maxright左边
                RL[i]=min(RL[2*Pos-i],MaxRight-i)
            else:  #i在maxright右边，以i为中心的回文串还没扫到，此时，以i为中心向两边扩展
                RL[i]=1#RL=1：只有自己
 
            #以i为中心扩展，直到左！=右or达到边界(先判断边界)
            while i-RL[i]>=0 and i+RL[i]<len(s) and s[i-RL[i]]==s[i+RL[i]]:
                RL[i]+=1
 
            #更新Maxright pos:
            if RL[i]+i-1>MaxRight:
                MaxRight=RL[i]+i-1
                Pos=i
 
            #更新最长回文子串的长;
            Maxlen=max(Maxlen,RL[i])
        s=s[RL.index(Maxlen)-(Maxlen-1):RL.index(Maxlen)+(Maxlen-1)]
        s=s.replace('#','')
        return s