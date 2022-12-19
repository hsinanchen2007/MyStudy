    从新添加的一列中地砖的排布状况入手，有如下几种状况：
一：一块竖着排的多米诺瓷砖：dp[i-1]
二：两块横着的多米诺瓷砖分别占据新一列中的上下两个正方形:dp[i-2]
三：L形的托米诺瓷砖占据新加入的一列（L形瓷砖有两种摆法，图示中仅给出了其中一种，另一种类似）:
2*dp[k from 0 to i-3]
![image.png](https://pic.leetcode-cn.com/aa7568152c5151e791fe458cefbfd76033492e2a795043f1c54d29aad2bc1a88-image.png)
    将三种情况加总即得**dp[i]=dp[i-1]+dp[i-2]+2*dp[k from 0 to i-3]**
    有了递推公式后，可以看到我们用三个变量即可保存之前的状态，只需要O(1)的空间复杂度
```
class Solution:
    def numTilings(self, N: int) -> int:
        a,b,total=1,2,1 ####a,b,total 分别代表dp[i-2],dp[i-1],dp[k from 0 to i-3]
        if N==1:
            return 1
        for i in range(3,N+1):
            temp=b
            b+=a+2*total  
            total+=a
            a=temp
        return b%(10**9+7)
```

