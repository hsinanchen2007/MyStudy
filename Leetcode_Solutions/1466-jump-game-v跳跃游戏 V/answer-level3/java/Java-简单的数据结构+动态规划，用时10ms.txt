站在一根柱子上，既可以往左跳也可以往右跳，只要在范围内。对于任意的柱子，能访问到的柱子数等于往左或往右跳到的那一个柱子所能访问的数目再加它本身。所以可以用一个一维数组 `dp[]` 来存放每个柱子最多能访问的数量。
使用递归可以利用 `dp[]` 的值来免去排序之类的处理，使得解法更加简洁快速。
在跳的过程中（`d`范围内），如果遇到了比当前柱子高或等的柱子，就不再往更远的地方跳了。

这里使用 dp 数组来记忆的一个技巧就是避免重复计算。对于每一根柱子，他最小的访问数目是1，就是他自己（比如左右紧挨着的柱子都比它高），数组初始化的时候每一个元素都是0，后面的遍历中，如果取到的柱子`i`有 `dp[i]!=0`，说明这个柱子已经计算过了，直接取这个值就可以用，而无需重新计算；如果`dp[i]`是0，就要获取它左边或右边数目最大的柱子，再+1。注意一下限制条件。
通过这种记忆化的方法将递归结果存储下来的类似题目还有 [329.矩阵中的最长递增路径](https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/)。

代码和相关注释：

```
class Solution {
    int[] arr;
    int n; //数组长度
    int d;
    int[] dp;   //用来存储每个柱子的最大结果
    public int maxJumps(int[] arr, int d) {
        this.arr = arr;
        this.n = arr.length;
        this.d = d;
        dp = new int[n];
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = Math.max(ans, getMaxFromOnePoint(i));
        }
        return ans;
    }
    
    private int getMaxFromOnePoint(int p){
        if(dp[p] != 0)  return dp[p];   //当前柱子已经计算过，直接返回它的值
        // 如果没有，分别计算它往左和往右跳一次可以得到的最大值
        int leftMax = 0;    
        int l = 1;  // 往左跳的距离
        while(p-l>=0 && l<=d){
            if(arr[p-l]>=arr[p]){   //遇到了高柱子挡路，只能结束
                break;
            } else{
                if(dp[p-l]==0)  dp[p-l] = getMaxFromOnePoint(p-l);
                leftMax = Math.max(leftMax, dp[p-l]);
                l++;
            }
        }
        // 同理右边  
        int rightMax = 0;
        int r = 1;
        while(p+r<n && r<=d){
            if(arr[p+r]>=arr[p]){
                break;
            } else{
                if(dp[p+r]==0)  dp[p+r] = getMaxFromOnePoint(p+r);
                rightMax = Math.max(rightMax, dp[p+r]);
                r++;
            }
        }

        return Math.max(leftMax, rightMax)+1;
    }
}
```
