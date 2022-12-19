### 152. Max Product Subarray 乘积最大的连续子序列
例子
[2，3，-2，4]  max为[2,3] => 6
[-2, 0, -1]   max为[0],[-2, 0, -1] => 0
[2, 3, -10, 5, -1]  因为负负得正，所以max为[2, 3, -10, 5, -1]  =>300

最简单的办法就是枚举所有结果，记录乘积结果并更新最大值，即递归实现。
第二种方法时动态规划实现：问题的求最优解，并且最优解可以从子问题的最优解构建
第三种是基于负数元素的奇偶性

### 暴力递归
假设条件中的连续子序列条件不存在，即任意子序列的最大乘积。那结果的构成可以简单化为每个元素是否在加入乘积子序列中
#### 初始化
imax = Integer.MIN_VALUE,记录历史最大值, default product = 1 子序列乘积值
#### 结束条件
当每个元素都做了相同的处理，及递归的次数为n == nums.length
#### 逻辑处理
对于当前元素是否加入乘积结果
1. product1 = product * nums[0]，加入
2. product2 = product，不加入
然后比较两者最大值和历史最大值，得到最大值
int max_value = Math.max(product * nums[i], product);
imax = Math.max(max_value, imax);
#### 进入下一层
当前元素已经处理完成，得到的乘积值有两个product1，product2
分别对两个乘积值，对第二个元素做相同的处理，

所以最终**乘积最大的不连续连续子序列**的求解代码为
```
int max = Integer.MIN_VALUE;

public int maxProduct(int[] nums) {
    if (nums == null || nums.length == 0) {
        return -1;
    }
    helper(nums, 1, 0);
    return max;
}
private void helper(int[] nums, int product, int i) {
    if (i == nums.length) {
        return;
    }

    int select = nums[i] * product;
    int max_value = Math.max(product, select);
    max = Math.max(max_value, max);

    helper(nums, product, i + 1);
    helper(nums, select, i + 1);

}
```
#### 根据题意连续的子序列解
区别在于不选择当前元素加入结果乘积的product2需重置，则product2为当前元素，即新子序列的开始
```
private void helper(int[] nums, int product, int i) {
    if (i == nums.length) {
        return;
    }

    int select = nums[i] * product;
    int max_value = Math.max(nums[i], select);
    max = Math.max(max_value, max);

    helper(nums, nums[i], i + 1);
    helper(nums, select, i + 1);

}
```

### 动态规划实现
#### 动态规划两部曲
1. 状态定义
2. 状态转移方程

#### 从递归解法中简单可以分析出一个dp方程
dp[i] = dp[i-1] * nums[i],但发现若所有的元素为正数，则改dp方程正确，但有负数则不正确，所以在分析得
当nums[i] < 0, 则dp[i]最大值，为dp[i-1]负数最小值 * nums[i]
当nums[i] > 0, 则dp[i]最大值，为dp[i-1]正数最大值 * nums[i]

所以dp方程的定义应该定义成二位数组dp[i][2] 
dp[i][1] 表示 0到i子序列的最大值
dp[i][0] 表示 0到i子序列的最小值

因此新的DP方程为
dp[i][1]  = nums[i] >= 0 ? dp[i-1][1] * nums[i] : dp[i-1][0] * nums[i]
dp[i][0]  = nums[i] >= 0 ? dp[i-1][0] * nums[i] : dp[i-1][1] * nums[i]
```
public int maxProduct(int[] nums) {
    if(nums == null || nums.length == 0) {
        return -1;
    }
    int[][] dp = new int[nums.length][2];
    dp[0][0] = nums[0];
    dp[0][1] = nums[0];
    int ans = nums[0];
    for(int i = 1; i < nums.length; i++) {
        dp[i][1] = Math.max(dp[i-1][1] * nums[i], Math.max(dp[i-1][0] * nums[i], nums[i])); // 取最大值
        dp[i][0] = Math.min(dp[i-1][1] * nums[i], Math.min(dp[i-1][0] * nums[i], nums[i])); // 取最小值
        ans = Math.max(ans, dp[i][1]); // 更新最大值
    }
    return ans;
}
```
时间复杂度O(n)
空间复杂度O(n) 开辟了一个二维数组

### DP优化
从二维数组的解法中发现，求解dp[i][1]或者dp[i][0]，只需要得到dp[i-1][1]， dp[i-1][0]便可以求解，所以我们可以用变量curMax,curMin替代
```
public int maxProduct(int[] nums) {
    if(nums == null || nums.length == 0) {
        return -1;
    }
    int curMin = nums[0];
    int curMax = nums[0];
    int ans = nums[0];
    for(int i = 1; i < nums.length; i++) {
        int temp = curMax; // 记录，curMax会被覆盖
        curMax = Math.max(curMax * nums[i], Math.max(curMin * nums[i], nums[i])); // 取最大值
        curMin = Math.min(temp * nums[i], Math.min(curMin * nums[i], nums[i])); // 取最小值
        ans = Math.max(ans, curMax); // 更新最大值
    }
    return ans;
}
```
时间复杂度O(n)
空间复杂度O(1)

### DP优化2
继续优化，curMin记录的是乘积最小值， curMax记录的是乘积最大值。
当nums[i] > 0时， curMax = Math.max(curMax, nums[i])，curMin = Math.min(curMin, nums[i]);
当nums[i] < 0时, curMin 与  curMax的最大值就应该交换。
```
public int maxProduct(int[] nums) {
    if(nums == null || nums.length == 0) {
        return -1;
    }
    int curMin = nums[0];
    int curMax = nums[0];
    int ans = nums[0];
    for(int i = 1; i < nums.length; i++) {
        if(nums[i] < 0) {
            int temp = curMax;
            curMax = curMin;
            curMin = temp;
        }
        curMax = Math.max(curMax * nums[i], nums[i]); // 取最大值
        curMin = Math.min(curMin * nums[i],nums[i]); // 取最小值
        ans = Math.max(ans, curMax); // 更新最大值
    }
    return ans;
}
```
时间复杂度O(n)
空间复杂度O(1)

### 解法三，首尾，尾首两次扫描
该解法是基于数组中负数元素个数的奇偶性，
若是偶数个负数元素，那product乘积最大值就是所有元素的乘积结果
若是奇数个负数元素，那product乘积最大值需要从头到尾统计最大值，从尾到头统计最大值。两者最大值为最终的结果
如 -1 2，3， 那product为从尾到头扫描乘积的最大值，[2，3]
-1，2，3，-2，-3  那product为从尾到头扫描乘积的最大值[2，3，-2，-3]
-4，2，3，-2，-3 那product为从头到为扫描乘积的最大值[2，3，-2，-3]
所以基于例子，我们只需要进行左右两次扫描，同时记录最大值即可
注意，遍历过程中，当元素是0时，乘积则需要重置product = 1，重新统计，代码如下
```
public int maxProduct(int[] nums) {
    if(nums == null || nums.length == 0) {
        return -1;
    }
    int max = Integer.MIN.VALUE, len = nums.length, product = 1;
    for(int i = 0; i < len; i++) {
        max = Math.max(product *= nums[i], max);
        if(nums[i] == 0) product = 1;
    }
    product = 1;

    for(int i = len - 1; i >= 0; i++) {
        max = Math.max(product *= nums[i], max);
        if(nums[i] == 0) product = 1;
    }
    return max;
}
```
时间复杂度O(n)
空间复杂度O(1)

