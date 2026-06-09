### 解题思路
首先可以想到分治（递归实现）：遍历1到n，求出**以每个数字为根**有多少种可能，相加就是所求，而每一趟遍历中，**假设左右子树都已经求出了**，只需将这两个值相乘即可得到以当前数字为根的结果；对左右子树的计算可以调用当前函数递归求解。
![image.png](https://pic.leetcode-cn.com/7685e86ccc5f8eef1a46e7af287c2b871edd9e6083ce742406f2ba1064db3e99-image.png)


### 代码一

```cpp
class Solution {
public:
    int helper(int start, int end) {
        if (start > end) return 1;
        int ans = 0;
        for (int i = start; i <= end; i++) {
            // 求出左子树可能个数
            int left = helper(start, i - 1);
            // 求出右子树可能个数
            int right = helper(i + 1, end);
            // 上述两个结果相乘
            ans += left * right;
        }
        return ans;
    }
    
    int numTrees(int n) {
        if (n == 0) return 1;
        // 不需要求出具体的BST，只要个数
        // 遍历1到n，求出以每个数字为根有多少种可能，相加就是所求
        return helper(1, n);
    }
};
```
可以看到递归超时了，所以考虑动态规划。因为上述代码的重点在于左右子树个数相乘，这个过程可以用一个一维数组dp将以 i 为根的子树的结果保存起来，用 j 将子树分为左右两半，每次左子节点有 j - 1 个可能的取值，右子节点有 i - j 个可能的取值，因此在根位置固定（由 j 确定）的情况下，两两组合的结果就是dp[j - 1] * dp[i - j]。这里的外循环和递归时的区别是起始不再是1而是2，因为需要给出base case。
![image.png](https://pic.leetcode-cn.com/1da6dc391ee2a291895d37984ed401c6d8a50ad8eadb7d706a81df1c0bf1b469-image.png)


### 代码二
```cpp
class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 1;
        int dp[n + 1] ={0};
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
```