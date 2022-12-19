### 直观解法一：递归
##### 时间复杂度：O(6^n)（超时）
- 指数级别的复杂度
##### 空间复杂度：O(n)【递归栈的开销】

```java []
class Solution {//找规律：s共有 6^n种情况，共有5*n+1种不重复结果
    public double[] twoSum(int n) {
        //思路一：遍历 5*n+1种不重复结果，计算每一种不重复结果的组合个数
        double[] res=new double[5*n+1];
        int curSum=n;
        for(int i=0; i<res.length; ++i){
            res[i]=countSum(curSum, n)/Math.pow(6, n);
            ++curSum;
        }
        return res;
    }

    int countSum(int curSum, int n){
        if(n<0 || curSum<0){return 0;}
        if(n==0&&curSum==0){return 1;}
        int sum=0;
        for(int i=1; i<7; ++i){
            sum+=countSum(curSum-i, n-1);
        }
        return sum;
    }
}
```

### 进阶解法二：记忆化递归，用中间表存储递归已经解出的值：int[curSum，n]
### 再进化：动态规划
```java
class Solution {//找规律：s共有 6^n种情况，共有5*n+1种不重复结果
    public double[] twoSum(int n) {
        //思路二：动态规划（人人为我）
        /*
            子问题：
            状态：二维表 dp[n][6*n]：第n个筛子的“当前和”的出现次数
            转移方程：dp[n][j]=dp[n][j-1]+dp[n][j-2]+...+dp[n][j-6]
        */
        int[][] dp=new int[n][6*n];
        for(int j=0; j<6; ++j){dp[0][j]=1;} //初始状态
        for(int i=1; i<n; ++i){ //处理行
            for(int j=i; j<(i+1)*6; ++j){
                for(int dice=1; dice<7; ++dice){
                    if(j-dice < 0){break;}
                    dp[i][j]+=dp[i-1][j-dice];
                }
            }
        }
        double[] res=new double[5*n+1];
        int j=n-1;
        for(int i=0; i<res.length; ++i){
            res[i]=dp[n-1][j++]/Math.pow(6, n);
        }
        return res;
    }
class Result
}
```
##### 时间复杂度：O(n*6*n*6)即O(n^2)
##### 空间复杂度：O(n^2)
- 动态规划还可以进一步进行空间优化...
- 更一般的解题思路：当暴力法时间复杂度为指数级别时，都可以考虑记忆化递归，都可以考虑转化为自底向上的动态规划方法。