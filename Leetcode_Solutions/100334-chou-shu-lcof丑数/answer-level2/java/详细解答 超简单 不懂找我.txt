## 重难点题目
* [LeetCode重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)


**【核心思想】**
* 动态规划



**【思路】**
* 定义三个指针`p2,p3,p5`，`p2`指向的数字永远乘2，`p3`指向的数字永远乘3，`p5`指向的数字永远乘5
* 初始化所有指针都指向第一个丑数，即1
* 我们从`2*dp[p2], 3*dp[p3], 5*dp[p5]`选取最小的一个数字，作为新的丑数。这边新的丑数就是`2*dp[p2]=2*1=2`，然后`p2++`
* 此时`p3和p5`指向第1个丑数，`p2`指向第2个丑数。然后重复上一步
* 这里基于的一个事实是，丑数数列是递增的，当`p5`指针在当前位置时，后面的数乘以5必然比前面的数乘以5大，所以下一个丑数必然是先考虑前面的数乘以5。`p2,p3`同理，所以才可以使用指针


**【代码】**
```java
  public int nthUglyNumber(int n) {
    int p2=0,p3=0,p5=0;
    int[] dp=new int[n];
    dp[0]=1;
    for(int i=1;i<n;i++){
        dp[i]=Math.min(dp[p2]*2,Math.min(dp[p3]*3,dp[p5]*5));
        if(dp[i]==dp[p2]*2) p2++;
        if(dp[i]==dp[p3]*3) p3++;
        if(dp[i]==dp[p5]*5) p5++; 
    }
    return dp[n-1];
}
```


**【关注微信公众号，带你拿大厂offer】**

![logo_gif.gif](https://pic.leetcode-cn.com/f6d7085de4095860835e77030f7fd659dc589c02e9fbc0ed5e125ca913d1b15f-logo_gif.gif)

