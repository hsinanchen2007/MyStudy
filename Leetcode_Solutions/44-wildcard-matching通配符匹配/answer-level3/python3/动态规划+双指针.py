[@powcai](/u/powcai/) 感谢这位大神，如有冒犯，请私聊。

方法一：动态规划

画了张图，结合代码去看容易理解一点

楼主有点懒，没有过多的解释了。。。。

![QQ图片20190828214556.jpg](https://pic.leetcode-cn.com/88fa9864cc28af455e811994c9962994765036b14d8c359755a0d0161292fd1c-QQ%E5%9B%BE%E7%89%8720190828214556.jpg)


    class Solution:
        def isMatch(self, s: str, p: str) -> bool:
            #if not p:return not s
            #dp
            ns =len(s)
            np = len(p)
            dp = [[False]*(np+1) for _ in range(ns+1)]
            dp[0][0] = True
            for i in range(1,np+1):
                if p[i-1] == '*':
                    dp[0][i] = dp[0][i-1]
                    
            for i in range(1,ns+1):
                for j in range(1,np+1):
                    if p[j-1] == s[i-1] or p[j-1] =='?':
                        dp[i][j] = dp[i-1][j-1]
                    elif p[j-1] == '*':
                        dp[i][j] = dp[i-1][j] or dp[i][j-1]
            return dp[-1][-1]


第二种：双指针(比dp要快很多啊)

还是直接看代码吧，不多bb

    class Solution:
        def isMatch(self, s: str, p: str) -> bool:
            if not p:return not s
            #双指针
            i=j = i_shadow = 0
            #'s'匹配的位置
            start = -1  #*出现的位置
            while i <len(s):
                if j<len(p) and p[j] in {s[i],'?'}:
                    i+=1
                    j+=1
                #如果遇到’*‘ 先按匹配空字符处理，在不断向后扩展。
                elif j<len(p) and p[j]=='*':    
                    start = j
                    i_shadow = i
                    j += 1
                #不断扩展i,直到遇到一个s[i]==('*'号后面的字符)，然后再继续匹配
                elif start != -1:
                    j = start+1
                    i_shadow +=1
                    i = i_shadow
                else:
                    return False
            #s匹配完成，p可能还没有遍历完，进一步处理
            for x in p[j:]:
                if x !='*':
                    return False
            return True
            #return all(x == '*' for x in p[j:])




