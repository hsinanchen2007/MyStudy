### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    int min = Integer.MAX_VALUE;
    public int minimumTotal(List<List<Integer>> triangle) {
        //minimumTotal(triangle, 0, 0, 0, 0);
        int [][] dp = new int[triangle.size()][triangle.get(triangle.size()-1).size()];
        
        for (int i = 0; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle.get(i).size(); ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = triangle.get(i).get(j);
                }
                else if (i != 0 && j == 0) {
                    dp[i][j] = dp[i-1][j] + triangle.get(i).get(j);
                }
                else if (j == triangle.get(i).size() - 1) {
                    dp[i][j] = dp[i-1][j-1] + triangle.get(i).get(j);
                }
                else {
                    dp[i][j] = Math.min(dp[i-1][j-1], dp[i-1][j]) + triangle.get(i).get(j);
                }
            }
        }
        min = dp[triangle.size()-1][0];
        for (int i = 1; i < dp[triangle.size()-1].length; ++i) {
            min = Math.min(min, dp[triangle.size()-1][i]);
        }
        return min;
    }

    private void minimumTotal(List<List<Integer>> triangle, int sum, int y, int x, int level) {
        
        int n = triangle.size();
        if (level >= n) {
            min = Math.min(min, sum);
            return;
        }
        int m = triangle.get(level).size();
        if (x >= m || y >= n) {
            return;
        }
        int val = triangle.get(y).get(x);
        sum += val;
        minimumTotal(triangle, sum, y + 1, x, level + 1);
        minimumTotal(triangle, sum, y + 1, x + 1, level + 1);
        sum -=val;
    }


}
```