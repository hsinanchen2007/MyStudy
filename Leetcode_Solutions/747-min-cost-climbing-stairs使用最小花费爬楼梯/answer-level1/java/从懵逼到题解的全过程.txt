### 题意解析
cost数组是从每个阶梯继续向上走所需的体力，而登顶是走到数组外，最后一个元素也要算体力值，这也是为什么题目中的第二个样例结果是6而不是5。

---
### 动态规划
从[@liweiwei1419](/u/liweiwei1419/)在本题的题解评论中，能找到两条关于动态规划的总结：
+ 从一个最小的子问题开始，以后遇到的问题都可以从之前的子问题中得出答案
+ 由于要记录子问题的答案，这就是最最常见而且朴素的“以空间换时间”的思想，也是“规划”这个词英文的本意：“打表格”法。

个人觉得十分受用，先感谢一波~！

---
### 状态转移方程
我个人理解的状态转移方程的构造过程就在第一点中，如何通过一个子问题的表达式去表示全局的问题，我最开始得到的一个状态转移方程：**F(n) = Min(F(n+1)+cost[n],F(n+2)+cost[n])** 
大概的想法就是从当前这个阶梯往上爬，看走一个阶梯还是走两个阶梯消耗的体力值比较小。
这个状态转移方程我的实现代码如下：
```java
    /**
     * Min(F(n+1)+cost[n],F(n+2)+cost[n])
     * <p>
     * 递归超时:因为计算了太多的子问题。
     */
    public static int minCostClimbingStairs(int[] cost) {
        int res = Math.min(helper(cost, 0), helper(cost, 1));
        return res;
    }

    private static int helper(int[] cost, int n) {
        if (n >= cost.length) return 0;
        return Math.min(helper(cost, n + 1) + cost[n], helper(cost, n + 2) + cost[n]);
    }

```
---
### dp数组
在第一步没走通的时候，就可以考虑上面提到的第二点，如何用数组去打表格，记录子问题的结果。这里需要注意的是要仔细思考dp数组的含义。这道题中，dp数组可以看做是记录走到当前阶梯***i***，继续向上所需的最小体力值。
那么如何得到这个dp[i]呢？能到达**i**处的只有**i-1**与**i-2**处的阶梯，然后再加上从当前这个阶梯向上爬所需的体力值，dp[i]的计算等式就可以表示为：
**dp[i] = Min(dp[i-2],dp[i-1])+cost[i]** （其中**i**对应每一个阶梯）
而从最开始的题意解析中可知，[登顶]的意思是走到数组之外，我们可以看做在阶梯之外还有一个消耗体力值为0的额外阶梯。
以题目中第一个样例[10,15,20]为例,可得dp数组相关示意图：
![dp数组计算图.jpg](https://pic.leetcode-cn.com/be73970010f13729e61cef6a6abcf2934bf876ebbf367ef75e8b19ea3bea7c1e-dp%E6%95%B0%E7%BB%84%E8%AE%A1%E7%AE%97%E5%9B%BE.jpg)
图中dp数组最开始的两个元素0是干嘛的呢？因为我们要计算第0级阶梯所需的体力值，而根据上面的公式计算的话，就会越界了，所以干脆再补两个元素去表示，因此就有了这两个0元素。
实现代码如下：
```java
    /**
     * dp数组
     * <p>
     * 时间：100%
     * 空间：5%
     */
    public static int minCostClimbingStairs(int[] cost) {
        int len = cost.length;
        // dp数组存放的是 走到当前台阶 所需的最小体力值
        // 多的三个台阶是因为最开始的两个 与最后登顶的最后一个。
        int[] dp = new int[len + 3];
        // 这里是给dp数组赋值，因此要赋值到最后一个元素之前即可
        for (int i = 2; i < dp.length - 1; i++) {
            // 状态转移方程，能够到当前这个台阶的 分别是前一个台阶与前一个台阶的前一个台阶。
            // cost[i-2]相当于向右偏移了两位
            dp[i] = Math.min(dp[i - 2], dp[i - 1]) + cost[i - 2];
        }
        // 这里这么写是为了好理解 -> 这里对应的是登顶那一个台阶(超过了cost范围的那一阶)
        // 这一个台阶对应的体力值为0
        dp[dp.length - 1] = Math.min(dp[dp.length - 3], dp[dp.length - 2]) + 0;
        return dp[dp.length - 1];
    }
```
---
### 对dp数组的优化
从dp数组的实现中我们可以看到，其实只需要dp[i-1]与dp[i-2]这两个数就可以了，因此分别用两个变量表示即可。实现代码如下：
```java
    /**
     * 优化：从dp数组中我们可以看到，其实只需要dp[i-1]与dp[i-2]这两个数就可以了
     * <p>
     * 时间：100%
     * 空间：50%
     */
    public static int minCostClimbingStairs(int[] cost) {
        int bb = 0;//记录前一个的前一个dp数
        int b = 0;//记录前一个dp数
        for (int i = 0; i < cost.length; i++) {
            // 记录前一个dp数的值，为bb的赋值做准备
            int temp = b;
            // 因为走到这一步的，可能是前一个阶梯的，也可能是前两个阶梯的，因此求这两个地方的最小值
            b = Math.min(b, bb) + cost[i];
            // 向右移动一位
            bb = temp;
        }
        return Math.min(bb, b);
    }
```
---
以上，感谢大家能耐心看完~我也是萌新一枚，如果有错希望大家能够指正。
