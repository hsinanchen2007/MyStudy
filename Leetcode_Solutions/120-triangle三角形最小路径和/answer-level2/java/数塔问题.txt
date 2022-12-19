经典的数塔问题。见：http://acm.hdu.edu.cn/showproblem.php?pid=2084

看到题的时候，就感觉是数塔问题，结果第一次读题看花了，没有注意到“每一步只能移动到下一行中相邻的节点”-----相邻！
导致一次 WA。。。。



```
class Solution {

    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null || triangle.isEmpty()) {
            return 0;
        }
        int len = triangle.size();
        int[] dp = new int[len + 1];
        for (int j = len - 1; j >= 0; j--) {
            for (int i = 0; i <= j; i++) {
                dp[i] = triangle.get(j).get(i) + Math.min(dp[i], dp[i + 1]);
            }
        }
        return dp[0];
    }
}
```
