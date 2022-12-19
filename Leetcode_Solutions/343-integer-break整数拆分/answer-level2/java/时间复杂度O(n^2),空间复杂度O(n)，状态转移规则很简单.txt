### 解题思路
![QQ截图20200326151525.png](https://pic.leetcode-cn.com/218a301ae9a228767b8bbe41136aad0b1ec5300de9119e6b55c949b25a8cd542-QQ%E6%88%AA%E5%9B%BE20200326151525.png)

不知道还能不能再优化，按照传统的dp思想去解决会很简单
题目描述中给出的用例：10 = 3 + 3 + 4, 3 × 3 × 4 = 36。算是在给人挖坑，当我们考虑一个数的拆分情况时，只需要考虑一个数被两个数相加的情况就可了，不要再往下拆分，否则就只能列举所有拆分的可能情况，那样就成了暴力了。比如10={1+9,2+8,3+7,4+6,5+5}，其中7的最优值dp_max[7]=12，3的最优值dp_max[3]=3，3*12=36是这所有5种拆分情况下的最大值，那么dp_max[10]=36，这里用到的dp_max[7],dp_max[3]也是在前面这样计算并保存下来的。

dp_max[i]表示MAX{i本身，i的各拆分部分之积的最大值}
实际上，只有当i>=5时，才是i的各拆分部分之积的最大值（也就是题目要求的最优值）更大，此时dp_max[i]的值才是题目要求的解，所以在2<=n<=4的情况下，我单独处理了。比如，当后面计算的dp_max[i]需要用到dp_max[2]，显然，我们应该返回2，而不是2的拆分最大值1。

至于为什么当n>=5时拆分之积一定大于它自己，我只能说：显然，可得


状态转移方程；
dp[each_num]={


max(dp_max[i]*dp_max[each_num-i]),其中1<=i<=each_num/2

},其中5<=each_num<=n

返回dp_max[n]

### 代码

```java
class Solution {
    public int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        //从4开始以后的每一个数，其通过拆分得到的积都大于其本身，不要问我为什么，猜的
        int []dp_max=new int[n+1];//n>=5，从下标1开始使用dp表
        dp_max[1]=1;
        dp_max[2]=2;
        dp_max[3]=3;
        dp_max[4]=4;
        //当下面用到的加数小于5时，使用它们本身而不是它们的拆分值，因为小于5时它们本身更大
        //只有当加数大于等于5时，才用它们的拆分值
        for(int each_num=5;each_num<=n;each_num++){
            dp_max[each_num]=dp_max[1]*dp_max[each_num-1];//初始化，比如5=1+4，此时给dp_max[5]赋值1*4
            for(int i=2;i<=each_num/2;i++){//i<=each_num/2即可,因为拆分各部分之积与顺序无关
                if(dp_max[i]*dp_max[each_num-i]>dp_max[each_num]) dp_max[each_num]=dp_max[i]*dp_max[each_num-i];
            }

        }
        return dp_max[n];


    }
}
```