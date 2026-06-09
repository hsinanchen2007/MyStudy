首先说说解题思路，下面的解法都是围绕这个思路展开。

思路：n 构成的二叉搜索树的种数 F(n) 等于以 1～n 各个数为根节点的种数 S(i) 之和。以某个数为根节点的二叉搜索树的种数等于其左子树构成的二叉搜索树种数乘以其右子树构成的二叉搜索树的种树。即 
F(n) = S(1) + S(2) + ... + S(n)。
S(i) = F(i的左子树) * F(i的右子数)。

### 方法一，递归
```
int numTrees(int n) {
    if (n == 0) return 0;
    return helper(1, n);
}

int helper(int start, int end) {
    if (start > end) {
        return 1;
    }
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += helper(start, i - 1) * helper(i + 1, end);
    }
    return sum;
}
```
很不幸超时，因为有重复的递归计算，哪里重复了呢。我们不考虑具体的数值，可以发现，相同长度的区间所构成的二叉搜索树的种数是一样的，比如1～3、4～6、7～9等等，长度都是3，但是构成的种数都是5，这就是重复的地方。直接的解决方法是对不同长度的值进行标记来避免重复计算。如下：
```
unordered_map<int, int> m;

int numTrees(int n) {
    if (n == 0) return 0;
    return helper(1, n);
}

int helper(int start, int end) {
    if (start > end) {
        return 1;
    }
    int sum = 0;
    for (int i = start; i <= end; i++) {
        int lft = m[i - 1 - start] ? m[i - 1 - start] : helper(start, i - 1);
        int rgt = m[end - i - 1] ? m[end - i - 1] : helper(i + 1, end);
        sum += lft * rgt;
    }
    m[end - start] = sum;
    return sum;
}
```
这样就顺利AC了。

### 方法二，二维动态规划
```
int numTrees(int n) {
    int dp[101][101] = {0};
    for (int start = n; start >= 1; start--) {
        for (int mid = start; mid <= n; mid++) {
            if (start > mid - 1) dp[start][mid - 1] = 1;    //左边出界
            if (mid + 1 > n) dp[mid + 1][n] = 1;            //右边出界
            dp[start][mid - 1] = dp[start + 1][mid - 1 + 1];//右移一步
            dp[start][n] += dp[start][mid - 1] * dp[mid + 1][n];
        }
    }
    return dp[1][n];
}
```
还是相同的思路，需要注意的是这里是从右向左展开，所以右子树的值一定存在，对左子树计算向右平移一位就可以了。

### 方法三，一维动态规划
```
int numTrees(int n) {
    if (n == 0) return 0;

    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int end = 2; end <= n; end++) {
        for (int mid = 1; mid <= end; mid++) {
            dp[end] += dp[mid - 1] * dp[end - mid];
        }
    }

    return dp[n];
}
```
仍然是同样的思路，这里用的一维空间。对于下面这行代码：
`dp[end] += dp[mid - 1] * dp[end - mid];`
解释之后很好理解，dp[i] 既可以表示为 i 个数构成的二叉搜索树种数，也可以表示为长度为 i 的 [1, i] 区间的二叉搜索树种数。又由于前面讲的，相同长度不同区间的值相等，所以对于右子树的区间 [mid + 1, end] 向左移动 mid 即为 [1, end - mid] == dp[end - mid]

