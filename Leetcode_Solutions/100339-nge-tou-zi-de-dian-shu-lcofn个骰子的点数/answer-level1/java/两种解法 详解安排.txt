## 重难点题目
* [LeetCode重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)


#### 解法1：动态规划（二维数组）
**【核心思想】**
* f(n,s)=f(n-1,s-1)+f(n-1,s-2)+f(n-1,s-3)+f(n-1,s-4)+f(n-1,s-5)+f(n-1,s-6) 

**【数据结构】**
* 二维数组


**【思路】**
* 确定问题解的表达式。可将f(n, s) 表示n个骰子点数的和为s的排列情况总数
* 确定状态转移方程。n个骰子点数和为s的种类数只与n-1个骰子的和有关。因为一个骰子有六个点数，那么第n个骰子可能出现1到6的点数。所以第n个骰子点数为1的话，f(n,s)=f(n-1,s-1)，当第n个骰子点数为2的话，f(n,s)=f(n-1,s-2)，…，依次类推。在n-1个骰子的基础上，再增加一个骰子出现点数和为s的结果只有这6种情况！那么有：f(n,s)=f(n-1,s-1)+f(n-1,s-2)+f(n-1,s-3)+f(n-1,s-4)+f(n-1,s-5)+f(n-1,s-6) 
* 上面就是状态转移方程，已知初始阶段的解为：当n=1时, f(1,1)=f(1,2)=f(1,3)=f(1,4)=f(1,5)=f(1,6)=1。


**【代码】**
```java
public double[] twoSum(int n) {
    int[][] dp=new int[n+1][6*n+1];
    double[] ans=new double[5*n+1];
    double all=Math.pow(6,n);
    for(int i=1;i<=6;i++)
        dp[1][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=6*n;j++){
            for(int k=1;k<=6;k++){
                dp[i][j]+=j>=k?dp[i-1][j-k]:0;
                if(i==n)
                    ans[j-i]=dp[i][j]/all;
            }
        }
    }
    return ans;
}
```
**【备注】**
* 由于每个dp[i][j]只于i-1时刻的状态有关，所以可以删去一个维度，简化算法

#### 解法2：动态规划（一维数组）
**【数据结构】**
* 一维数组


**【思路】**
* 在上述解法的基础上，删去一个维度
* 第二个循环从后往前遍历，**避免覆盖**

**【代码】**
```java
public double[] twoSum(int n) {
    if(n==0)
        return new double[0];
    double[] dp=new double[6*n+1];
    double[] ans=new double[5*n+1];
    double all=Math.pow(6,n);
    for(int i=1;i<=6;i++){
        dp[i]=1;
        ans[i-1]=1.0/6;
    }
    for(int i=2;i<=n;i++){
        for(int j=6*n;j>=1;j--){
            int temp=0;
            for(int k=1;k<=6;k++){
                temp+=(j>=k)?dp[j-k]:0;
            }
            dp[j]=temp;
            if(i==n && j>=n){
                ans[j-i]=dp[j]/all;
            }
        }
    }
    return ans;
}
```
**【关注微信公众号，带你拿大厂offer】**

![logo_gif.gif](https://pic.leetcode-cn.com/f6d7085de4095860835e77030f7fd659dc589c02e9fbc0ed5e125ca913d1b15f-logo_gif.gif)
