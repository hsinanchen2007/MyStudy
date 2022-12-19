### 解题思路
看代码说话：)

### 代码

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        //1. 初始化最后一层数据
        int m = triangle.size();
        List<Integer> list = triangle.get(m - 1);
        int n = list.size();
        int[] dp = new int[m];
        for (int j = 0; j < n; j++) {
            Integer integer = list.get(j);
            dp[j] = integer;
        }
        //2. start DP
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < triangle.get(i).size(); j++) {
                dp[j] = Math.min(dp[j], dp[j + 1]) + triangle.get(i).get(j);
            }
        }
        return dp[0];
    }
}
```