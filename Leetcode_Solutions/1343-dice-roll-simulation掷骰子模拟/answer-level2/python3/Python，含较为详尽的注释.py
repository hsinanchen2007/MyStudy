建立三维数组nums[i][j][cnt]，表示第i次掷出j点且是连续第cnt次掷出了j点。所以最终对nums[-1][j]求和可以得到第n次掷出j点的总的可能数，再让j循环0-5求和，即可得到答案。

在计算数组nums[i+1][k]时，仅需考虑与nums[i][j]的关系，即第i+1次掷出k点，仅与第i次掷出j点有关，若j!=k，则求和；若j==k，则根据rollMax[j]允许的连续次数对nums[i][j][1~rollMax[j]]（闭区间）求和。

竞赛的时候死磕错误解法，结束之后看了别人的代码才知道连续次数的信息必须保留。
写以下解法的时候，把心理活动写在注释里了。 Hope it help :)

```
class Solution:
    def dieSimulator(self, n: int, rollMax):
        MOD = 10 ** 9 + 7
        nums = [[[0 for _ in range(16)] for _ in range(6)] for _ in range(n)]
        for i in range(6):
            nums[0][i][1] = 1 # 第1次掷骰子，点数为i且连续一次
        for i in range(1,n): # 第i次掷骰子，0-start
            for j in range(6): # 第i次掷出j点，j=0~5表示1-6点
                for k in range(6): # 第i-1掷出k点，k=0~5表示1-6点
                    if j!=k: # 若i次与i-1次点数不同，无需考虑重复问题，因为每个数字至少可连续出现一次（rollMax>=1）
                        # 对第i-1次掷出k点的情况，无论是连续的第几次，都求和；此处暗含两次求和，
                        #一个是数组第三维由sum()求和，另一个是随着k的循环，不断累加得出nums[i][j][1]的值
                        nums[i][j][1] += sum(nums[i-1][k]) % MOD 
                    else:
                        # 若k与j相同，即当前点数与上一次点数相同，则需考察连续次数小于rollMax[j-1]的情况；
                        #在第i次连续掷出j点m次的序列数等于在第i-1次连续掷出j点m-1次的序列数量。
                        for m in range(2,rollMax[j-1]+1): 
                            nums[i][j][m] = nums[i-1][j][m-1]
        ans = [0,0,0,0,0,0]
        for j in range(6):
            ans[j] = sum(nums[-1][j]) % MOD
        return sum(ans) % MOD
```
