执行用时 :2 ms, 在所有 java 提交中击败了98.70% 的用户
内存消耗 :37.7 MB, 在所有 java 提交中击败了60.03%的用户
```
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int len = triangle.get(triangle.size()-1).size();
        int[] dp = new int[len+1];
        for(int i = triangle.size()-1; i >= 0; i--){
            List<Integer> al = triangle.get(i);
            for(int j = 0; j < al.size(); j++){
                dp[j] = al.get(j)+Math.min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
}
```
