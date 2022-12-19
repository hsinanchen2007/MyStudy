### 自顶向下的动态规划
**要使得删除的字符最少，只需找到两字符串的最长公共子串。**
显然求最长公共子串这一问题具有递归的属性：
对于长度分别为l1, l2的两字符串，如果它们各自的最后一个字符相等，则它们的最长公共子串长度可表述为：
```
lcs(l1, l2) = lcs(l1 - 1, l2 - 1) + 1
```
如果它们各自的最后一个字符不相等，例如，"abcd"和"abc"，这时的最长公共子串长度可表述为：
```
lcs(l1, l2) = max{ lcs(l1 - 1, l2), lcs(l1, l2 - 1) }
```
为了避免在递归中大量的重复计算，设置备忘录memoization，memoization[i][j]表示第一个字符串从0~i，第二个字符串从0~j，它们的最长公共子串。**注意将备忘录的初始值设为-1**，以正确判断lcs(i, j)是否已经计算过。
具体代码实现如下：
```
class Solution{
    public int minDistance(String word1, String word2) {
        int l1 = word1.length(), l2 = word2.length();
        memoization = new int[l1][l2];
        for (int i = 0; i < memoization.length; i++) {
            for (int j = 0; j < memoization[0].length; j++) {
                memoization[i][j] = -1;
            }
        }
        int lcs = getLCS(word1, word2, l1 - 1, l2 - 1);
        return l1 + l2 - 2 * lcs;
    }
    private int[][] memoization;
    private int getLCS(String word1, String word2, int i, int j){
        if(i == -1 || j == -1)
            return 0;
        if(memoization[i][j] != -1)
            return memoization[i][j];
        int lcs;
        if(word1.charAt(i) == word2.charAt(j))
            lcs = getLCS(word1, word2, i - 1, j - 1) + 1;
        else lcs = Math.max(getLCS(word1, word2, i - 1, j), getLCS(word1, word2, i, j - 1));
        memoization[i][j] = lcs;
        return lcs;
    }
}
```
### 一般动态规划
同样根据上面的思路，只是这时先从下标0开始计算dp数组的值。由于dp[i][j]要么和dp[i - 1][j]、dp[i][j - 1]相关，要么和dp[i - 1][j - 1]相关，只需要按照自左向右，自上而下的顺序遍历计算dp数组即可。
```
class Solution{
    public int minDistance(String word1, String word2) {
        int l1 = word1.length(), l2 = word2.length();
        int[][] dp = new int[l1 + 1][l2 + 1];
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if(word1.charAt(i - 1) == word2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return l1 + l2 - 2 * dp[l1][l2];
    }
}
```
