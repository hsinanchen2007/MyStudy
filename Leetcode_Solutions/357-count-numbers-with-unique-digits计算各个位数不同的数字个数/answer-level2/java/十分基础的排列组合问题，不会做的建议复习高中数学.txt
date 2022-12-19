### 解题思路
![QQ截图20200402162427.png](https://pic.leetcode-cn.com/25f66dfea99df9d52595d32fbffb58c51c9b167310a70117f1bbf593fdbf43d9-QQ%E6%88%AA%E5%9B%BE20200402162427.png)

dp[i]为i位数的各位数字都不同的数字 x 的个数：
初始化dp[1]=10,dp[2]=9乘9;
dp[i]=dp[i-1]乘(10-i+1);
例如dp[3]=9乘9乘8=dp[2]乘8.......//百位9种可能（除去0），十位9种可能(除去百位用过的），个位8种可能（除去百位和十位用过的）
通过使用dp表里前面已经计算好的部分省去计算当前元素时重复做的乘法运算
因为只有当是一位数字时可能首位是0，所以使用dp表时从十位开始使用


### 代码

```java
class Solution {
    public int countNumbersWithUniqueDigits(int n) {
 if(n==0) return 1;
        if(n==1) return 10;
        int [] dp=new int[n+1];//从下标1开始使用
        dp[1]=10;//一位数
        dp[2]=81;//两位数：9*9
        int sum=dp[1]+dp[2];
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]*(10-i+1);
            sum+=dp[i];
        }
        return sum;
    }
}
```