其实我觉得这个题是个0-1背包问题，我们可以将问题抽象为：
```java
f(i,target)：抛掷前i+1个硬币，正面朝上的硬币数等于target的概率
当前投出target可以是（1）当前没投出正面，前i个投出target（2）当前投出正面，前i个投出target-1
f(i,target) = f(i-1,target-1)*prob[i]+f(i-1,target)*(1-prob[i])
```
首先使用记忆化搜索。
老规矩，先写自顶向下，这里格外要注意的就是不能出现dfs（1,3），因为现在prob中就两枚硬币（i=0,1），肯定不能出现3个正面向上的硬币。
```java
class Solution {
    double[][]memo;
    public double probabilityOfHeads(double[] prob, int target) {
        //f(i,target)抛掷前i个硬币，正面超上的硬币数等于target的概率
        //当前投出target可以是（1）当前没投出正面，前i-1个投出target（2）当前投出正面，前i-1个投出target-1
        //f(i,target) = f(i-1,target-1)*prob[i]+f(i-1,target)*(1-prob[i])
        memo = new double[prob.length][target+1];
        for(int i=0;i<prob.length;i++)
        {
            Arrays.fill(memo[i],-1);
        }
        return dfs(prob,prob.length-1,target);
    }
    public double dfs(double[] prob, int index,int target)
    {
        //终止条件
        //（1）target最大只能为0（2）当前prob中硬币的个数小于target值，肯定摇不出target
         if(target<0||index+1<target)
            return 0;
        if(memo[index][target]!=-1)
            return memo[index][target];
        //初始条件
        if(index==0){
            if(target==1)
                return prob[0];
            else
                return 1-prob[0];
        }
        //常规
        memo[index][target] = dfs(prob,index-1,target-1)*prob[index]+dfs(prob,index-1,target)*(1-prob[index]);
        return memo[index][target];
    }
}
```
写出自顶向下的代码，就可以知道哪些条件应该是初始条件了，将初始条件赋值到dp数组中
```java
class Solution {
    public double probabilityOfHeads(double[] prob, int target) {
        /*
        dp[i,target]代表抛掷前i个硬币，正面超上的硬币数等于target的概率
        当前投出target可以是（1）当前没投出正面，前i-1个投出target（2）当前投出正面，前i-1个投出target-1
        dp[i,target] = dp[i-1,target-1]*prob[i]+dp[i-1,target]*(1-prob[i])
        */
        double result = 1;
        //如果target=0
        if(target==0){ 
            for(double coin:prob)
                result = result*(1-coin);
            return result;
        }
        int N = prob.length;
        double [][]dp = new double[N][target+1];
        dp[0][0] = 1-prob[0];
        dp[0][1] = prob[0];
        for(int i=1;i<prob.length;i++)
        {
            for(int j=0;j<=target;j++)
            {
                //不能让当前prob中可用的硬币数（i+1）小于j（正面超上的硬币数）
                if(i+1<j)
                    break;
                dp[i][j] = dp[i-1][j]*(1-prob[i]);
                if(j-1>=0)
                dp[i][j]+=dp[i-1][j-1]*prob[i];
            }
        }
        return dp[N-1][target];
    }
}
```
大家都知道背包问题可以优化空间，将二维数组优化为一维数组，只不过要注意在从后向前遍历。
可以看出转移方程为：
```java
 dp[i,target] = dp[i-1,target-1]*prob[i]+dp[i-1,target]*(1-prob[i])
```
第i行的结果只与第i-1行的数值有关系，因此可以只使用一维的数组来存储数值。

```java
class Solution {
    public double probabilityOfHeads(double[] prob, int target) {
        /*
        dp[i,target]代表抛掷前i个硬币，正面超上的硬币数等于target的概率
        当前投出target可以是（1）当前没投出正面，前i-1个投出target（2）当前投出正面，前i-1个投出target-1
        dp[i,target] = dp[i-1,target-1]*prob[i]+dp[i-1,target]*(1-prob[i])
        */
        double result = 1;
        //如果target=0
        if(target==0){ 
            for(double coin:prob)
                result = result*(1-coin);
            return result;
        }
        int N = prob.length;
        double []dp = new double[target+1];
        dp[0] = 1-prob[0];
        dp[1] = prob[0];
        for(int i=1;i<prob.length;i++)
        {
            for(int j=target;j>=0;j--)
            {
                if(j>i+1)
                    continue;
                dp[j] = dp[j]*(1-prob[i]);
                if(j-1>=0)
                dp[j]+=dp[j-1]*prob[i];
            }
        }
        return dp[target];
    }
}
```
