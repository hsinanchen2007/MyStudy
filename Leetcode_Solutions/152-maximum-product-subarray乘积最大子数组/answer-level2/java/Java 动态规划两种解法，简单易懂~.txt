**方法1**：二维DP，第二维存储正和负的标记;DP[i][j]的意义是考察到第第i个元素时，选中i的情况下的最大乘积和最小乘积。

因为需要考虑到负负得正的情况，所以每个元素选中后的正负最大值都需要保存，又因为必须是连续的子数组，所以，如果i-1时的最大或最小值和当前值相乘都小于当前值，那最大值就取当前值即可，最小值同理。

所以写出递推公式：

DP[i][0] = max(DP[i - 1][0] * a[i], DP[i - 1][1] * a[i], a[i]);

DP[i][1] = min(DP[i - 1][0] * a[i], DP[i - 1][1] * a[i], a[i]);

最后求解的值是max(DP[0][0],...,DP[n - 1][0])

```java
//dp[i][j] j代表0,1 正的最大值和负的最小值;i表示当前值选中的情况下
//DP[i][0] = max(DP[i - 1][0] * a[i], DP[i - 1][1] * a[i], a[i]);
//DP[i][1] = min(DP[i - 1][0] * a[i], DP[i - 1][1] * a[i], a[i]);
public int maxProduct(int[] nums) {
    if (nums == null || nums.length == 0) return 0;
    int n = nums.length;
    if (n == 1) return nums[0];
    int[][] dp = new int[n][2];
    if (nums[0] > 0) dp[0][0] = nums[0];
    else if (nums[0] < 0) dp[0][1] = nums[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i], nums[i]);
        dp[i][1] = min(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i], nums[i]);
    }

    int max = dp[0][0];
    for (int i = 1; i < n; i++) {
        max = Math.max(dp[i][0], max);
    }
    return max;
}

private int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

private int max(int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}
```
**方法2**：常数级二维DP。

从方法1可以看出, 当前dp[i]的状态只和dp[i - 1]有关，并且我们最终需要的结果是在遍历dp[0][0]->dp[n - 1][0]中得到的，所以我们可以不用在第一维中开辟n个空间，只要开辟2个空间即可，只存储上一个i - 1和当前i,并且根据奇偶性不断滚动替换即可。


```java
public int maxProduct(int[] nums) {
    if (nums == null || nums.length == 0) return 0;
    int n = nums.length;
    if (n == 1) return nums[0];
    // 状态压缩 只需要前一个值和当前值，至于最大值，我们在递推过程中不断覆盖即可。
    int[][] dp = new int[2][2];
    if (nums[0] > 0) dp[0][0] = nums[0];
    else if (nums[0] < 0) dp[0][1] = nums[0];

    int res = dp[0][0];
    for (int i = 1; i < n; i++) {
        dp[i & 1][0] = max(dp[(i - 1) & 1][0] * nums[i], dp[(i - 1) & 1][1] * nums[i], nums[i]);
        dp[i & 1][1] = min(dp[(i - 1) & 1][0] * nums[i], dp[(i - 1) & 1][1] * nums[i], nums[i]);
        res = Math.max(res, dp[i & 1][0]);
    }
    return res;
}

private int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

private int max(int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}
```