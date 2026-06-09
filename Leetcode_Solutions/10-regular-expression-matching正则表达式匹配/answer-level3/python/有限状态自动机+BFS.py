学过编译原理就知道，最开始就是讲用自动机去进行词法句法分析

这道题其实简单了很多，按照两种情况构造自动机就好了

情况一：
无"*"
增加点B，如果x是"a-z"，则x为对应字符的边，如果是"."，则x为26条边，分别对应a-z
A---x-->B

有"*"
增加点B，从A向B连一条不需要字符的"*"边，然后从B向自己连一条x的边，x和前一种情况对应
        --x--
        |   |
        |   |
A---*-->B<---

有人会有疑问，为什么这里要加一个点B，而不是直接A向自己连自环，因为对于a*b*的情况，如果都是A向自己连自环，则可以匹配ba，而增加点B则可以避免这种情况

然后是用这个自动机来判断是否能够匹配，原理很简单，BFS即可，但要注意，由于*边的存在，当A变为对时，将B也要变成对，因为他们对应的是同一个集合（对应代码中的Expand）
具体的BFS实现很暴力，这也是现在自动机匹配缺乏多项式解的原因。

class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        st = 0
        cnt = 0
        length = len(p)
        E = [[]] * (length+1)
        for i in range(length+1):
            E[i] = list()
        
        p = p + "."
        for i in range(length):
            if (p[i] == "."):
                if (p[i+1] != "*"):
                    for j in range(26):
                        E[cnt].append([chr(j+97), cnt+1])
                    cnt += 1
                else:
                    E[cnt].append(["", cnt+1])
                    cnt += 1
                    for j in range(26):
                        E[cnt].append([chr(j+97), cnt])
            else:
                if (p[i] == "*"):
                    continue
                if (p[i+1] != "*"):
                    E[cnt].append([p[i], cnt+1])
                    cnt += 1
                else:
                    E[cnt].append(["", cnt+1])
                    cnt += 1
                    E[cnt].append([p[i], cnt])
        ed = cnt
        cnt = cnt+1
        length = len(s)
        now = [0] * cnt
        now[st] = 1
        now = self.Expand(now, E)
        
        for i in range(length):
            nxt = [0] * cnt
            flag = 1
            
            for j in range(cnt):
                if (now[j] == 1):
                    for v in E[j]:
                        if (v[0] == s[i]):
                            nxt[v[1]] = 1
            nxt = self.Expand(nxt, E)
            now = nxt
        return now[ed] == 1
    
    def Expand(self, V, E):
        n = len(V)
        flag = 1
        while (flag != 0):
            flag = 0
            for j in range(n):
                if (V[j] == 1):
                    for v in E[j]:
                        if (v[0] == "" and V[v[1]] == 0):
                            V[v[1]] = 1
                            flag = 1
        return V