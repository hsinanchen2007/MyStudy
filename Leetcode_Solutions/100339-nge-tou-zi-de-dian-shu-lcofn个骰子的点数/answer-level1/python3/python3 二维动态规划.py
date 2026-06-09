### 解题思路
二维动态规划

### 代码

```python
class Solution:
    def twoSum(self, n: int) -> List[float]:
        res=[]
        #要求每一个出现的点数出现的总数，开辟一个二维数组dp dp[n][j]表示n个骰子投掷后，总数为j的出现次数
        dp=[[0 for _ in range(6*n+1)] for _ in range(n+1)]
        #(1) 初始状态
        for j in range(1,7):#初始化第一行
            dp[1][j]=1
        for i in range(2,n+1): #每1行
            for j in range(i,6*i+1):#每一列，要计算的每一列的数量是不一样的，为6i,即i枚骰子，有5i种结果，需要填充的数量为5i
                for z in range (1,7):#是转移方程dp[i][j]=dp[i-1][j-1]+dp[i-1][j-2]+...+dp[i-1][j-6]
                    if j-z>=1 and dp[i-1][j-z]>0:
                        dp[i][j]+=dp[i-1][j-z]
        for i in range(6*n+1):
            if dp[n][i]/6**n>0:
                res.append(dp[n][i]/6**n)
        print(res)
        return res
        

                
       



```