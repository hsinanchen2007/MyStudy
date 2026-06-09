### 解题思路
真的，当时我距离AC就差那么一点点了，就差一个等于号。
一开始我用的是暴力递归，把每一个点的跳跃次数都求出来，然后向上返回最大的跳跃次数，结果在第51个样例的时候超时了，然后我就用dp优化了一下，加了个备忘录，用来保存第i个点的最大跳跃次数，然后每次递归开始之前判断一下是否已经求过这个点的最大跳跃次数，然后过了141/150，第141个应该输出15，我输出了一个14，因为是递归，检查了了老半天没看出哪里错了，吃完饭后又冥思苦想了半个小时，突然发现我往左跳的时候设置了j > 0，吐了，改成j >= 0就对了。看了看其他人的题解，也有用的自底向上的dp，就是先把数组排个序，然后从小的数字开始往上走。我也想到了，但是觉得不如自顶向下的递归清楚，但是递归真的不好检查，出了问题都不知道怎么改

### 代码

```java
class Solution {

    public int maxJumps(int[] arr, int d) {
        if (arr.length == 0) {
            return 0;
        }
        int max = 0;
        int[] dp1 = new int[arr.length];
        for (int i = 0; i < arr.length; i++) dp1[i] = -1; 
        int[][] dp = new int[arr.length][arr.length];
        for (int i = 0; i < arr.length; i++) {
            int num = jump(i, arr, dp, d, dp1);
            if (max < num) max= num;
        }
        return max;
    }
    
    int jump(int i, int[] arr, int[][] dp, int d, int[] dp1) {
        if (dp1[i] != -1) return dp1[i] + 1;
        for (int j = i - 1; j >= 0 && j >= i - d; j--) {
            if (arr[j] < arr[i]) {
                dp[i][j] = jump(j, arr, dp, d, dp1);
            } else {
                break;
            }
        }
        for (int j = i + 1; j < dp.length && j <= i + d; j++) {
            if (arr[j] < arr[i]) {
                dp[i][j] = jump(j, arr, dp, d, dp1);
            } else {
                break;
            }
        }
        int max = 0;
        for (int j = 0; j < dp[0].length; j++) {
            if (max < dp[i][j]) max = dp[i][j];
        }
        dp1[i] = max;
        return max + 1;
    }
}
```