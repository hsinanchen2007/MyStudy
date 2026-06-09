class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        n=len(startTime)
        data=sorted(zip(endTime,startTime,profit),key=lambda x: x[0])
        last_cloest=[-1]*n
        for i in range(n-1,-1,-1): #从后往前找与其最邻近的工作
            start=data[i][1]
            for j in range(i-1,-1,-1):
                end=data[j][0]
                if end<=start:
                    last_cloest[i]=j
                    break
        dp=[0]*(n+1)
        #计算顺序 从前往后
        for i in range(n):
            # max不做当前的兼职 /做当前的兼职
            dp[i+1]=max(dp[i],dp[last_cloest[i]+1]+data[i][2])
        return dp[n]