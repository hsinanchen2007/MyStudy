### 解题思路
从king开始向八个可能的方向出发，分别为上下左右，左上，左下，右上，右下八个方向， 每个方向最先遇到的queen就是能攻击king的， 把这个queen加入列表并停止该方向遍历。

### 代码

```java
class Solution {
    public List<List<Integer>> queensAttacktheKing(int[][] queens, int[] king) {
        List<List<Integer>> ans = new ArrayList<>();
        boolean[][] matrix = new boolean[8][8];
        for (int[] queen : queens) {
            matrix[queen[0]][queen[1]] = true;
        }
        int[][] steps = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        for (int[] step : steps) {
            for (int x = king[0], y = king[1]; x >= 0 && x < 8 && y >= 0 && y < 8; x += step[0], y += step[1]) {
                if (matrix[x][y]) {
                    List<Integer> tmp = new ArrayList<>();
                    tmp.add(x);
                    tmp.add(y);
                    ans.add(tmp);
                    break;
                }
            }
        }
        return ans;
    }
}
```