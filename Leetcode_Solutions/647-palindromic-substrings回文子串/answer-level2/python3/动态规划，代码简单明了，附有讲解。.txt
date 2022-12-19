    def countSubstrings(self, s: str) -> int:
        dp=[[0 for i in range(len(s))] for i in range(len(s))]

        for i in range(len(s)):
            dp[i][i]=1

        k=len(s)-1
        p=1
        while p!=len(s):
            for i in range(k):
                j=i+p
                if s[j]==s[i]:
                    if j==i+1:
                        dp[i][j]=1
                    elif dp[i+1][j-1]==1:
                        dp[i][j]=1
                    else:
                        continue
            p+=1
            k-=1
        res=0
        for resi in dp:
            res+=sum(resi)
        return res

如果从i到j的字符串是回文字符串，那么如果i-1和j+1相等，那么从i-1到j+1就是回文字符串。
当然，如果是1个字符串，那么一定是回文的，如果是两个字符串，并且相等，那么也是回文的。