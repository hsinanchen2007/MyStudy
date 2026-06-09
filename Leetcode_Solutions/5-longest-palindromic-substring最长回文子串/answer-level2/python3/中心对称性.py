class Solution:
    def longestPalindrome(self, s: str) -> str:
        #中心扩展
        maxs=''
        mids=''
        #奇数型中心对称
        for i in range(0,len(s)):
            for j in range(0,i+1):
                if((i-j)>=0 and (i+j)<=len(s)-1 and s[i-j]==s[i+j]):
                    mids=s[i-j:i+j+1]
                    if(len(mids)>len(maxs)):
                        maxs=mids
                else:
                     break
        #偶数型对称
        for i in range(len(s)-1):
            for j in range(0,i+1):
                if(s[i]==s[i+1]):
                    if((i-j)>=0 and (i+j+1)<=len(s)-1 and s[i-j]==s[i+1+j]):
                        mids=s[i-j:i+j+2]
                        if(len(mids)>len(maxs)):
                            maxs=mids
                    else:
                        break
                else:
                    break
        return maxs
                      
