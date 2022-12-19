### 解题思路
动态规划有2种写法，一种是记忆化递归，一种是迭代
1.记忆化递归这里没啥思路，就是遍历每一个数，选择拿或者不拿，拿的话`n-i`就进入下一层递归，不拿的话`n不变`，在当前的循环for loop进行`i--`，循环结束时在所有的结果里面取max
2.迭代写法有个状态转移方程:`dp[i]=Math.max(dp[i],Math.max(dp[i-j]*j,(i-j)*j))`，其中，`(i-j)*j`是说只将整数n拆分成2个数考虑，而`dp[i-j]*j`是考虑将整数n不断拆分，取两者的最大值。
3.我当初也没写对状态转移方程，只是考虑了将整数不断拆分`dp[i-j]*j`，后面有一个测试用例`n=4`，没法通过不断拆分得到结果，反而只考虑拆分成2个数（2*2=4）的时候，乘积最大

### 代码

```
int memo[];//记忆化搜索
    public int integerBreak(int n) {
        
        memo=new int[n+1];
        Arrays.fill(memo,-1);
        return recursion(n-1,n);
    }
    //start为搜索起点，从后往前
    //rest是减剩余的值
    private int recursion(int start,int rest){
        if(rest==0){
            return 1;
        }
        
        if(memo[rest]!=-1){//如果备忘录中有值，就提前返回
            return memo[rest];
        }
        int ans=1;
        for(int i=start;i>0;i--){
            if(rest>=i){//拿或不拿
                ans=Math.max(ans,i*recursion(i,rest-i));//拿了 i ，就乘以 i ,当剩余的数为0时，就return 1
            }
            //不拿,i--
        }
        memo[rest]=ans;//在做完所有的选择后，取它们的最大结果
        return ans;
    }    
```
**迭代写法**

```java
class Solution {    
    
    public int integerBreak(int n) {
        
        int[] dp=new int[n+1];//dp[i]:容量为n时，能够凑出的最大乘积
        
        dp[1]=1;//容量为1能凑出的最大乘积是1
        dp[2]=1;
        for(int i=3;i<=n;i++){
            for(int j=1;j<=i-1;j++){
                //dp[i-j]*j是可以拆分成3个数及以上的乘积,(i-j)*j只考虑将i拆分为2个数的乘积
                dp[i]=Math.max(dp[i],Math.max(dp[i-j]*j,(i-j)*j));
            }
        }
        return dp[n];
    }
    
}
```