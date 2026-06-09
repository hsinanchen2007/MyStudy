### 解题思路
题目的本质是求：n个骰子投出n~6n个点数的概率分别是多少；只需计算所有情况数及投出某个点数的情况数，相除即可；
**1、总的情况数**
想象依次排列的n个骰子，每个骰子都可以取值1~6，故n个筛子的情况总数为6^n；
**2、投出total点的情况数**
为了方便说清楚(也许就是单纯的固执:)，此处考虑total如何分布在n个骰子上；
第n个筛子可以分配的最大点数是：total-(n-1)*1，即其余都是1后的剩余点数，且不能超过6；
第n个筛子可以分配的最小点数是：total-(n-1)*6，即其余都是6后的剩余点数，且不能小于1；
当第n个骰子投出k点后，只需剩余total-k个点如何分布在(n-1)个骰子上。
**3、整体思路**
递归公式：f(total, n) = ∑ f(total-k, n-1)，其中k ∈ [min, max]；
再将其中的中间计算结果保存起来以调高效率，典型的动态规划解法；

### 代码

```java
class Solution {
    public static int[][] buff;
    public double[] twoSum(int n) {
        buff = new int[6*n+1][n+1];
        double total = 1.0;
        for(int i = 1; i <= n; i ++) total *= 6;

        double[] res = new double[5 * n + 1];
        for(int i = 0; i < res.length; i ++)
            res[i] = f(n + i, n) / total;
        return res;
    }

    public int f(int points, int n){
        if(buff[points][n] > 0)
            return buff[points][n];
        if(n == 1){
            buff[points][n] = 1;
            return 1;
        }
        int min = Math.max(1, points - 6 * (n-1));
        int max = Math.min(6, points - (n-1));
        
        int res = 0;
        for(int i = min; i <= max; i ++)
            res += f(points - i, n - 1);
        
        buff[points][n] = res;
        return res;
    }
}
```