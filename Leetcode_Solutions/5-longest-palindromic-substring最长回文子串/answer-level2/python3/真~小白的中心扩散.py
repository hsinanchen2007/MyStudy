```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        odd_hw_indexs=[]#奇数位
        even_hw_indexs=[]#偶数位
        ls=len(s)

        if ls==0:
            return ""
        elif ls==2 and s[0]==s[1]:
            return s
        else:
            re_str,re_l=s[0],0
        #获取扩散中心
        for i in range(1,ls):
            if s[i]==s[i-2]:
                odd_hw_indexs.append(i-1)
        for i in range(1,ls):
            if s[i]==s[i-1]:
                even_hw_indexs.append(i-1)
        #分别遍历奇数位和偶数位扩散中心，马拉车算法的第一步就是合并这两类
        for odd_hw_index in odd_hw_indexs:
            left,right=odd_hw_index-2,odd_hw_index+2
            while left>-1 and right<ls:
                if s[left]==s[right]:
                    left-=1
                    right+=1
                else:
                    if right-left-1>re_l:
                        re_str=s[left+1:right]
                        re_l=right-left-1
                    break
            if right-left-1>re_l and (left==-1 or right==ls):
                re_str=s[left+1:right]
                re_l=right-left-1
        
        for even_hw_index in even_hw_indexs:
            left,right=even_hw_index-1,even_hw_index+2
            while left>-1 and right<ls:
                if s[left]==s[right]:
                    left-=1
                    right+=1
                else:
                    if right-left-1>re_l:
                        re_str=s[left+1:right]
                        re_l=right-left-1
                    break
            if right-left-1>re_l and (left==-1 or right==ls):
                re_str=s[left+1:right]
                re_l=right-left-1
        
        return re_str
        
        
```
