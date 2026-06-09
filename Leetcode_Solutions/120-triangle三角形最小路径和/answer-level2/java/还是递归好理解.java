memo存的是每个位置最小的值

```
class Solution {

    private int[][] memo;

    public int minimumTotal(List<List<Integer>> triangle) {
        // 重复子问题：每个点的路径和 = Min(左下子路径和， 右下子路径和) + 当前点的值
        // 状态方程：dp[i][j] = Min(dp[i + 1][j], dp[i + 1][j + 1]) + dp[i][j]
        memo = new int[triangle.size()][triangle.get(triangle.size() - 1).size()];
        return helper(0, 0, triangle);
    }

    private int helper(int i, int j, List<List<Integer>> triangle){
        if (triangle.size() - 1 == i && j < triangle.get(i).size()){
            return triangle.get(i).get(j);
        }
        if (memo[i][j] != 0) return memo[i][j];
        int value1 =  helper(i + 1, j, triangle);
        int value2 =  helper(i + 1, j + 1, triangle);
        memo[i][j] = Math.min(value1, value2) + triangle.get(i).get(j);
        return memo[i][j];
    }
}
```
