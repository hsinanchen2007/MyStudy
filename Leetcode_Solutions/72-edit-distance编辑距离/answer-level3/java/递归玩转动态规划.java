- 首先理解一下暴力递归的思路：
![编辑距离](https://pic.leetcode-cn.com/28aac500f3a8228d034a9fd230f3647b6fe0d3e29ed0c4b87f1e0cf85a702f1b.png)

- 下面展示出暴力递归的代码，这里用了哈希表存储了中间重复计算的结果，在很多情况下这是一个非常好用的方法，但是他的效果和动态规划还是有非常大的差距。
```
    // 编辑距离
    public int minDistance2(String word1, String word2) {
        if(word1.equals("")) return word2.length();
        if(word2.equals("")) return word1.length();
        HashMap<String,Integer> memo = new HashMap<>();
        return  getRes(word1,0,word2,0,memo);
    }

    // 暴力递归，添加一个哈希map存储重复计算的结果
    private int getRes (String s1, int c1, String s2, int c2,HashMap<String,Integer> memo) {
        if(c1 == s1.length()) return s2.length() - c2;
        if(c2 == s2.length()) return s1.length() - c1;
        String key = c1 + "@" + c2;
        if(memo.containsKey(key)) return memo.get(key);
        int ans = 0;
        if(s1.charAt(c1) == s2.charAt(c2)){
            ans = getRes(s1,c1 + 1, s2, c2 + 1,memo);
        }else{
            int add = getRes(s1,c1 + 1, s2, c2,memo);
            int del = getRes(s1,c1,s2,c2 + 1,memo);
            int modify = getRes(s1,c1+1,s2,c2 + 1,memo);
            ans = 1 + Math.min(add,Math.min(del,modify));
        }
        memo.put(key,ans);
        return ans;
    }
```
- 下面再用dp数组优化一下代码，构成动态规划。
```
class Solution {
    public int minDistance(String word1, String word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int[][] dp = new int[len1 + 1][len2 + 1];
        for (int i = len1; i >= 0; i--) {
            for (int j = len2; j >= 0; j--) {
                if(i == len1) {
                    dp[i][j] = len2 - j;
                }else if(j == len2){
                    dp[i][j] = len1 - i;
                }else if(word1.charAt(i) == word2.charAt(j)){
                    dp[i][j] =dp[i + 1][j + 1];
                }else{
                    int add = dp[i + 1][j];
                    int del = dp[i][j + 1];
                    int modify = dp[i + 1][j + 1];
                    dp[i][j] =  1 + Math.min(add,Math.min(del,modify));
                }
            }
        }
        return dp[0][0];
    }
}
```