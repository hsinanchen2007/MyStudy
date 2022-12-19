## 重难点题目
* [LeetCode重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)


#### 解法1：动态规划【二维数组】
**【核心思想】**
* `dp[i][j]=dp[i-1][j]+dp[i][j-coins[i]]`

**【数据结构】**
* 二维数组

**【思路】**
1. 令 `dp[i][j]` 为遍历到当下这个硬币时，组成金额 j 的方法数目
2. 有两种可能性（1）当前这个硬币没有取，`dp[i][j]=dp[i-1][j]`；（2）当前这个硬币取了，`dp[i][j]=dp[i][j-coins[i]]`。最后的结果是两者的和
3. 将状态转移方程翻译成代码，并处理边界条件


**【代码】**
```java
public int waysToChange(int n) {
     int[][] dp=new int[4][n+1];
     int[] coins={1,5,10,25};

     for(int i=0;i<=n;i++)
         dp[0][i]=1;
     for(int i=0;i<4;i++)
         dp[i][0]=1;
         
     for(int i=1;i<4;i++){
         for(int j=1;j<=n;j++){
             if(j>=coins[i])
                 dp[i][j]=(dp[i-1][j]+dp[i][j-coins[i]])%1000000007;
             else
                 dp[i][j]=dp[i-1][j];
         }
     }
     return dp[3][n];
 }
```

#### 解法2：动态规划【一维数组】
**【核心思想】**
* 根据状态转移方程，化简上面的方法

**【数据结构】**
* 一维数组

**【思路】**
1. 从上面的状态转移方程可以看出，`dp[i][j]`只与`dp[i-1][j]`和`dp[i][j-coins[i]]`有关，所以完全可以把第一个维度除掉，只用一个一维数组存储


**【代码】**
```java
public int waysToChange2(int n) {
    int[] dp=new int[n+1];
    int[] coins={1,5,10,25};

    for(int i=0;i<=n;i++)
        dp[i]=1;
    
    for(int i=1;i<4;i++){
        for(int j=1;j<=n;j++){
            if(j>=coins[i])
                dp[j]=(dp[j]+dp[j-coins[i]])%1000000007;
        }
    }
    return dp[n];
}
```
![微信外logo.png](https://pic.leetcode-cn.com/65f129176e1493afc5daac0416705e1adea2b70495a0869b61ae418606399f4a-file_1582362912985)
