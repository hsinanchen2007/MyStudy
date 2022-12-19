### 解题思路
这题比较简单。注意观察规律。就是可以从1到n之间取一个数i，然后这个数的左边分成一段，右边分成一段。i作为根，左边的数作为i的左子树，右边的数作为i的右子树，这样i作为根的情况下，它的结构就有左子树的结构数目乘右子树的结构数目。至于左、右子树的结构数目，可以递归求解。
然后我们把这个i从1遍历到n。结果累加起来就行了


### 代码

```cpp
class Solution {
public:
    
    int do_numTrees(int n, vector<int>& dp) {
        if (dp[n] != 0) {
            return dp[n];
        }
        int res = 0;
        for (int i=1; i<=n; i++) {
            res = res + (do_numTrees(i-1, dp) * do_numTrees(n-i, dp));
        }
        dp[n] = res;
        return res;
    }

    int numTrees(int n) {
        if (n==0) {
            return 1;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else if (n == 3) {
            return 5;
        } else if (n == 4){
            return 14;
        } else {
        vector<int> dp = vector<int>(n+1, 0);
            dp[0] = 1;
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 5;
            return do_numTrees(n, dp);
        }
    }
};
```

递归解法
```cpp
class Solution {
public:
    int numTrees(int n) {
        if (n==0) {
            return 1;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else if (n == 3) {
            return 5;
        } else {
            int res = 0;
            for (int i=1; i<=n; i++) {
                res = res + (numTrees(i-1) * numTrees(n-i));
            }
            return res;
        }
    }
};
```