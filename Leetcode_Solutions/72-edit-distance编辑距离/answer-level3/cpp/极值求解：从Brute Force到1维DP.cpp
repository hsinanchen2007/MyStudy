又是让人一脸懵逼的每日打卡题，经过一早上的努力，小菜尝试总结下这道题的解题思路：
首先这是一道求极值的问题，那么最朴素的解法，莫过于遍历所有的值，然后算出极值，很惨的是，大部分人在这一步就已经跪了，感觉除了多刷题，没什么好的办法。。。
要遍历所有的值，最容易实现的方法是用递归，也就是DFS，想想遍历一个二叉树，用递归做简直无情地简单。对于这道题，暴力的遍历方法是，依次比较两个字符的每一位，如果相等，则进入下一轮比较，否则，依次计算对原字符3种不同操作后的结果，并取最小值。这里我实现了一个自底向上的递归算法：
```
    int dfs(string& word1, string& word2, int i, int j){
        if(i == word1.size()) return word2.size() - j;
        if(j == word2.size()) return word1.size() - i;
        int res = 0;
        if(word1[i] == word2[j]) res = dfs(word1, word2, i + 1, j + 1);
        else{
            int r1 = dfs(word1, word2, i + 1, j); //删除word1[i]
            int r2 = dfs(word1, word2, i + 1, j + 1); //修改word1[i]为word2[j]
            int r3 = dfs(word1, word2, i, j + 1); //在i位置插入字符word2[j]
            res = 1 + min(r1, min(r2, r3));
        }
        return res;
    }

    int minDistance(string word1, string word2){
        return dfs(word1, word2, 0, 0);
    }
```
暴力解法毫不意外的会超时，仔细想想发现，这里会对大量的[i,j]重复计算，因此需要剪枝，把已经计算过的i,j组合的结果保存起来，代码如下：
```
    int dfs(string& word1, string& word2, int i, int j, vector<vector<int>>& memo){
        if(i == word1.size()) return word2.size() - j;
        if(j == word2.size()) return word1.size() - i;
        if(memo[i][j] > 0) return memo[i][j];
        int res = 0;
        if(word1[i] == word2[j]) res = dfs(word1, word2, i + 1, j + 1, memo);
        else{
            int r1 = dfs(word1, word2, i + 1, j, memo); //删除word1[i]
            int r2 = dfs(word1, word2, i + 1, j + 1, memo); //修改word1[i]为word2[j]
            int r3 = dfs(word1, word2, i, j + 1, memo); //在i位置插入字符word2[j]
            res = 1 + min(r1, min(r2, r3));
        }        
        return memo[i][j] = res;
    }

    int minDistance(string word1, string word2){
        vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), 0));
        return dfs(word1, word2, 0, 0, memo);
    }
```
问题算到这里，时间复杂度O(MN)已经是最优解了，但递归调用栈会占用大量内存，如果要优化的话，就是把递归改为迭代，直接自底向上计算memo数组，也就是大佬们简洁精炼的DP算法：
```
    int minDistance(string word1, string word2) {
        int a = word1.size(), b = word2.size();
        vector<vector<int>> dp(a+1, vector<int>(b+1, 0));
        for(int i = 1; i <= a; i++) dp[i][0] = i;
        for(int j = 1; j <= b; j++) dp[0][j] = j;
        for(int i = 1; i <= a; i++){
            for(int j = 1; j <= b; j++){
                int d1 = dp[i-1][j];
                int d2 = dp[i][j-1];
                int d3 = dp[i-1][j-1];
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = d3;
                }else{
                    dp[i][j] = 1 + min(d1, min(d2, d3));
                }
            }
        }
        return dp[a][b];
    }
```
最后，我们还可以进一步优化空间，因为dp[i][j]的值只与它的邻居dp[i-1][j]、dp[i][j-1]、dp[i-1][j-1]有关，将二维数组压缩为一维数组，可以天然解决前两个依赖，问题就在于dp[i-1][j-1]的值如何保存，很显然，可以将这一维的数据压缩成一个值，于是，我们可以使用一个一维数组加一个变量来替换原来的二维数组，代码如下，这里写的冗余了一点，主要为了和上面对应起来：
```
    int minDistance(string word1, string word2) {
        int a = word1.size(), b = word2.size();
        vector<int> dp(b+1, 0);
        int pre = 0;    //存储了原来的dp[i-1][j-1]
        for(int i = 0; i <= b; i++) dp[i] = i;
        for(int i = 1; i <= a; i++){
            pre = dp[0];
            dp[0] = i;
            for(int j = 1; j <= b; j++){
                int tmp = dp[j];
                int d1 = dp[j-1];
                int d2 = dp[j];
                int d3 = pre;
                if(word1[i-1] == word2[j-1]){
                    dp[j] = d3;
                }else{
                    dp[j] = 1 + min(d1, min(d2, d3));
                }
                pre = tmp;
            }
        }
        return dp[b];
    }
```
最后，动态规划一定强于DFS+memo吗？在非极值问题上，好像还不一定，比如在子问题数量超多，而DFS可以进行高效剪枝的情况下，DFS+memo的效率会优于DP算法，比如这道题：https://leetcode-cn.com/problems/frog-jump/，请大佬们批评指针~