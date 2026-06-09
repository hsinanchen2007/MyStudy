![image.png](https://pic.leetcode-cn.com/db9a5e86636b3b636836d02c2e147020f2e286bdb1f144f709675ae5a6db345c-image.png)

一开始考虑的简单了，觉得贪心就能解决。因为对于当前位，替换一定优于插入和删除，只要长度不一致的就最后补齐。结果遇到一个例子
“abcdef”转换到“bcdefgh”，发现贪心的规则解决不了。

于是考虑状态转移方程，假设有两个指针 i,j 分别指向 word1和word2，那么有三种情况:
1. i,j 同时+1，如果指向相同字符则表示不需要操作，如果不同表示替换然后往后走一位
2. i+1, j不变，表示把word1中第i位删除或者在word2中第j位前插入一个字符匹配上word1[i]，这两者是等价的，所以后面只说删除操作
3. i不变, j+1，表示把word2中第j位删除或者在word1中第i位前插入一个字符匹配上word2[j]

边界条件就是i,j一个碰到头了，把另一个剩下的都删除了。
可以看到，从(i,j)=(0,0)出发，每次搜索3个后续状态，O(3^n)很快就超时，而总的状态只有O(len1*len2)，因此用空间换时间，把搜索过的状态存储下来即可。

```
class Solution {
    int dp[1005][1005];
public:
    int minDistanceFrom(string word1, string word2, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j]; 
        int len1 = word1.length();
        int len2 = word2.length();
        if (i == len1) return len2 - j;
        if (j == len2) return len1 - i;
        if (word1[i] == word2[j]) {
            dp[i][j] = minDistanceFrom(word1, word2, i+1, j+1);
            return dp[i][j];
        }
        
        int ans1 = minDistanceFrom(word1, word2, i, j+1);
        int ans2 = minDistanceFrom(word1, word2, i+1, j);
        int ans3 = minDistanceFrom(word1, word2, i+1, j+1);
        dp[i][j] = 1 + min(min(ans1, ans2), ans3);
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return minDistanceFrom(word1, word2, 0, 0);
    }
};
```


官方的代码没有用递归写法，会更快一点
```
class Solution {
  public int minDistance(String word1, String word2) {
    int n = word1.length();
    int m = word2.length();

    // 有一个字符串为空串
    if (n * m == 0)
      return n + m;

    // DP 数组
    int [][] D = new int[n + 1][m + 1];

    // 边界状态初始化
    for (int i = 0; i < n + 1; i++) {
      D[i][0] = i;
    }
    for (int j = 0; j < m + 1; j++) {
      D[0][j] = j;
    }

    // 计算所有 DP 值
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        int left = D[i - 1][j] + 1;
        int down = D[i][j - 1] + 1;
        int left_down = D[i - 1][j - 1];
        if (word1.charAt(i - 1) != word2.charAt(j - 1))
          left_down += 1;
        D[i][j] = Math.min(left, Math.min(down, left_down));

      }
    }
    return D[n][m];
  }
}
```

对于这种写法，还有些小技巧可以节省空间，因为每个新的状态只和左边，上方和左上的数据有关。因此只用一行就可以记录所有状态，更新的时候用新的数据替换这一列正上方的数据。代码如下：
```
class Solution {
public:
   int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();

    // 有一个字符串为空串
    if (n * m == 0)
      return n + m;

    // DP 数组
    vector<int> D(m + 1);

    // 边界状态初始化
    for (int j = 0; j < m + 1; j++) {
      D[j] = j;
    }

    // 计算所有 DP 值
    for (int i = 1; i < n + 1; i++) {
      int tmp = D[0];
      D[0] = i;
      for (int j = 1; j < m + 1; j++) {
        int left = D[j] + 1;
        int down = D[j - 1] + 1;
        int left_down = tmp;
        tmp = D[j];
        if (word1[i - 1] != word2[j-1])
          left_down += 1;
        D[j] = min(left, min(down, left_down));
      }
    }
    return D[m];
  }
};
```
极大减少内存消耗，空间复杂度为O(min(len1,len2))