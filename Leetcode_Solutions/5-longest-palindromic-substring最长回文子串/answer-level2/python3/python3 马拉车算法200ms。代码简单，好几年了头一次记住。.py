将这个代码分享给大家。
马拉车的具体解释很多题解都说了，我就不重复了，该解法是我从一个博客上看来的（出处不可考）。
特点是在头尾还加了两个字符$@来防止遍历越界（也就是不用考虑了，类似单调栈里首尾加两个0那种感觉）。
其他关键的我代码注释了
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if s=="":return ""
        s1 = '$#'+'#'.join(s)+'#@'
        mx = 0#已遍历的最大右边界
        mid = 0#对应的中心点
        l = len(s1)
        dp = [0]*l
        for i in range(1,l-1):
            if i<mx:#可以利用之前保存的值
                dp[i] = min(mx-i,dp[mid*2-i])#不能超过已遍历的右边界
            t = 0
            while 1:#继续扩张
                if s1[i+dp[i]+t]!=s1[i-dp[i]-t]:
                    break
                t+=1
            dp[i]+=t-1
            if i+dp[i]>mx:#更新边界值
                mx = i+dp[i]
                mid = i
        maxlen,maxidx=0,0
        for i in range(l):#找最大子串
            if dp[i]>maxlen:
                maxlen = dp[i]
                maxidx = i
        return s1[maxidx-maxlen:maxidx+maxlen+1].replace('#',"")
```
代码总共25行且考虑状况极少，看懂就能永久记住马拉车算法，最长回文串再也不怕啦！
希望对大家有帮助^_^