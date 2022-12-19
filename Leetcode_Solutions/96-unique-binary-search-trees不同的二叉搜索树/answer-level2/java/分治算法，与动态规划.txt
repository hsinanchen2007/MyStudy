### 解题思路
方法一：用分治的思维，将二叉树拆为左子树和右子树。
左子树的节点可以为0，那么右子树的节点数就是n-1-0.因为要去掉根节点。
分别计算出左子树的选择数与右子树的选择树，然后进行组合。就是当前节点数为i的树的数量。
因为最后有n个节点，那么就把从1，到n个节点，所有的树的数量相加。

### 代码

```java
class Solution {
    public int numTrees(int n) {
        if (n <= 1) {
            return 1;
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int left = numTrees(i);
            int right = numTrees(n - 1 - i);
            sum += left * right;
        }

        return sum;
    }
}
```
上述的方法会产生很多重复计算，比如多次计算节点为2的数量，这里采用一个缓存，将上述递归进行变形。

 class Solution {
    public int numTrees(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j-1];
            }
        }
        return dp[n];
    }
}

加缓存后变成了动态规划，在时间上节省了不少。
![image.png](https://pic.leetcode-cn.com/14dc04ee5635f1c33dcee63c4990f887dc2251c3e7acc1fd6a188d843ec9c384-image.png)
