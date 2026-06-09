## 题目讲解

**【历史重难点题目】**
* [历史重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)

**【核心思想】**
* 动态规划



**【思路】**
* 定义三个指针`p3,p5,p7`，`p3`指向的数字永远乘3，`p5`指向的数字永远乘5，`p7`指向的数字永远乘7
* 初始化所有指针都指向第一个丑数，即1
* 我们从`dp[p3]*3,dp[p5]*5,dp[p7]*7`选取最小的一个数字，作为新的丑数。这边新的丑数就是`3*dp[p3]=3*1=3`，然后`p3++`
* 此时`p5和p7`指向第1个丑数，`p3`指向第2个丑数。然后重复上一步
* 这里基于的一个事实是，丑数数列是递增的，当`p5`指针在当前位置时，后面的数乘以5必然比前面的数乘以5大，所以下一个丑数必然是先考虑前面的数乘以5。`p3,p7`同理，所以才可以使用指针


**【代码】**
```java
public int getKthMagicNumber(int k) {
    int p3=0,p5=0,p7=0;
    int[] dp=new int[k];
    dp[0]=1;
    for(int i=1;i<k;i++){
        dp[i]=Math.min(dp[p3]*3,Math.min(dp[p5]*5,dp[p7]*7));
        if(dp[i]==dp[p3]*3) p3++;
        if(dp[i]==dp[p5]*5) p5++;
        if(dp[i]==dp[p7]*7) p7++; 
    }
    return dp[k-1];
}
```
**【关注我，带你拿大厂offer】**
![微信公众号](https://pic.leetcode-cn.com/d06cc278fa9b2210e849de036017d591a6890b311261f97fc4a44ed8a1d7d1c2-logo_gif.gif)
