第一想法是动态规划，然后优化空间版动规，都不行，
再想到，其实无论什么数我只要保证我选了之后对手必败就行了，那什么时候必败，
最后一个必败情况是4，故选我是不是只要保证我选了之后对手面临的最后情况是4就行了，
那我就让对手面临的数一直保持为4的倍数能做到吗？
答案当然可以，因为我可以选123嘛，只要这个数本身不是4的倍数我就可以让对手选时一直保持4的倍数，最后他就输了
如果本身这个数就是4的倍数，我就输了
代码：```
def canWinNim(n):
    """解法一，动态规划"""
    if n <= 3:
        return True
    dp = [False] * n
    dp[0], dp[1], dp[2] = True, True, True
    for i in range(3, n):
        if not dp[i - 1] or not dp[i - 2] or not dp[i - 3]:
            dp[i] = True
    return dp[-1]
    
    

    """解法二，空间优化版的动归"""
    if n<=3:
        return True
    dp1,dp2,dp3=True,True,True
    for i in range(3,n):
        if not dp1 or not dp2 or not dp3:
            dp=True
        else:
            dp=False
        dp1, dp2, dp3 = dp2, dp3, dp
    return dp




    """解法三，其实只要保证你你一直你一直面对的是4的倍数就行"""
    return n%4!=0```
