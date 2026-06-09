class Solution:
    def generateParenthesis(self, n):         #动态规划
        if n <= 0: return [''] 
        re = [[''], ['()']]
        for i in range(2,n+1):
            re.append([])
            for j in range(i):
                for k in re[j]:                 #想要将k+l = i-1 的组合遍历仍旧需要两次循环
                    for l in re[i-1-j]:
                        re[i].append('(' + k + ')' + l)
        return re[n]
