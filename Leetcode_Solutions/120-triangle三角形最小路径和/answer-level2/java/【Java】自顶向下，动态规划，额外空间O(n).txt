``` java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int len = triangle.size();
        int[] dp = new int[len];
        dp[0]= triangle.get(0).get(0);
        int min = Integer.MAX_VALUE;

        for(int i=1;i<len;i++){
            dp[i] = dp[i-1] + triangle.get(i).get(i);
            for(int j=i-1;j>=1;j--){  // 第i层的j可由第i-1层的j和j-1到达
                dp[j] = Math.min(dp[j],dp[j-1]) + triangle.get(i).get(j);
            }
            dp[0] = dp[0] + triangle.get(i).get(0);
        }
        for(int k = 0;k<len;k++){
            min = dp[k]<min?dp[k]:min;
        }
        // System.out.println(Arrays.toString(dp));
        return min;
    }
}
```