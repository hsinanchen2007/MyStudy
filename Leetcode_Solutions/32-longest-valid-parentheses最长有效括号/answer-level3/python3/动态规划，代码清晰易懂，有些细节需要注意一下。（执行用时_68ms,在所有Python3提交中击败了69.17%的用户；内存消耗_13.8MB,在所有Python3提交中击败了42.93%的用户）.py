    def longestValidParentheses(self, s: str) -> int:
        if len(s) in [0,1]:return 0
        res=0
        dp=[0 for i in range(len(s))]
        for i in range(1,len(s)):
            if s[i]==')':
                if s[i-1]=='(':
                    if i-2>=0:
                        dp[i]=dp[i-2]+2
                    else:
                        dp[i]=0+2
                    if dp[i]>res:
                        res=dp[i]
                else:
                    if i-dp[i-1]-1>=0:
                        if s[i-dp[i-1]-1]=='(':
                            if i-dp[i-1]-2>=0:
                                dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2
                            else:
                                dp[i]=dp[i-1]+0+2
                        if dp[i]>res:
                            res=dp[i]
                        else:
                            continue
                    else:
                        continue
            else:
                continue
        return res