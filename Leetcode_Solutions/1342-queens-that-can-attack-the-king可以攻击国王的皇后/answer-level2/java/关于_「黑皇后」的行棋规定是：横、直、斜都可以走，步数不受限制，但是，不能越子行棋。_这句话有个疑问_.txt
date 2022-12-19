都可以走? 应该是指, 某个「黑皇后」只能沿横 [或] 直 [或] 斜, 不能有2种以上混合走法, 如果有的话, 这题就稍微复杂点了
以下是某个「黑皇后」只能已某一中走法【横 [或] 直 [或] 斜】的思路

[题目传送门](https://leetcode-cn.com/problems/queens-that-can-attack-the-king)

```
public List<List<Integer>> queensAttacktheKing(int[][] queens, int[] king) {
    List<List<Integer>> result = new LinkedList<List<Integer>>();
    int[][] flags = new int[8][8]; // 标志数组
    // 将数据放入二维数组中
    for (int[] queen : queens) {
        flags[queen[0]][queen[1]] = 1;
    }
    // 八个方向 上 / 下 / 左 / 右 / 左上 / 左下 / 右上 / 右下 查找
    int[][] directions = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
    for (int[] direction : directions) {
        int[] kingTmp = king;
        while (kingTmp[0] >= 0 && kingTmp[1] >= 0 && kingTmp[0] < 8 && kingTmp[1] < 8) { // 如果没有找到,继续往该方向查找
            int x = kingTmp[0] + direction[0];
            int y = kingTmp[1] + direction[1];
            if (x < 0 || y < 0 || x >= 8 || y >= 8) {
                break;
            }
            if (flags[x][y] == 1) {
                result.add(Arrays.asList(x, y));
                break;
            }
            kingTmp = new int[]{x, y};
        }
    }
    return result;
}
```
以题目描述第三个输入输出为测试数据: 0为空白区, 1为queen, 2为king, 得到下面的样子
1  1  0  1  1  1  1  1  
1  1  1  0  1  0  1  1  
0  1  1  1  0  0  1  1  
0  0  0  0  2  0  0  1  
1  0  1  1  0  1  1  0  
1  1  1  0  1  0  1  0  
0  1  0  1  1  0  0  0  
0  0  0  0  0  1  0  1 
再通过各个方向查找, 如果找到就不再继续查找此方向.
