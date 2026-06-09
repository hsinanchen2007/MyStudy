![搜狗截图20年02月15日1208_1.png](https://pic.leetcode-cn.com/800bf71bc409e3e2c465b1bdeb4c765a8c6410412c9d17f83cf8c80e4dac8b5c-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20%E5%B9%B402%E6%9C%8815%E6%97%A51208_1.png)

# 开门见山
dp[i]=dp[i-1]*2+dp[i-3]
# 分析
从初始状态[1,2,5]的n=1~3就能向后一次遍历到N，O(N)时间复杂度；且仅需要记录前三个答案的值，因此只需常数4个辅助空间，即O(1)空间复杂度。
# 证明
我们求dp[n]时
1.考虑从dp[n-1]基础上补2×1列图案，只有用1个多米诺的1种方案；
2.考虑从dp[n-2]基础上补2×2列图案，只有用2个多米诺的1种方案；（注**意，补的部分一定要不可从某列中间断开，否则会重复！比如两个竖着放的多米诺这种补法一定会和上面的一个竖着的方案重复**）
3.考虑从dp[n-x]基础上补2×2列图案，只有用2个托米诺+y个多米诺拼的2种方案；(x为2，3,4，……，n)
![微信图片_20200215123501.jpg](https://pic.leetcode-cn.com/231e6430864abe61140971b8f69b636620da460adc76dcd1a182e419fe36c8bc-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200215123501.jpg)
所以递推公式为
dp[n]=dp[n-1]+dp[n-2]+(dp[0]+dp[1]+...+dp[n-3])*2
再结合dp[n-1]=dp[n-2]+dp[n-3]+(dp[0]+dp[1]+...+dp[n-4])*2
可得dp[n]=dp[n-1]*2+dp[n-3]

```
def numTilings(self, N: int) -> int:
        '''
        dp=[1,1,2,5]
        if N<=3:return dp[N]
        for i in range(N-3):
            #x=dp[-1]+dp[-2]+sum(dp[:len(dp)-2])*2
            x=dp[-1]*2+dp[-3]
            dp.append(x)
        return dp[-1]%(10**9+7)'''
        dp=[1,1,2,5]
        if N<=3:return dp[N]
        dp_3,dp_2,dp_1=1,2,5
        for i in range(N-3):
            res=2*dp_1+dp_3
            dp_1,dp_2,dp_3=res,dp_1,dp_2
        return res%(10**9+7)
```
