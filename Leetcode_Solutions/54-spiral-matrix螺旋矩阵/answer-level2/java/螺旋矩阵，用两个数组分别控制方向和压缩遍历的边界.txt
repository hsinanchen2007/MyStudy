顺时针遍历数组的方向是右下左上即 {{ 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }} 
开始的时候的边界是 {0, yLen - 1, xLen - 1, 0}（与上面的方向顺序一致）
一旦遇到边界就要更改方向，并修改数组边界
具体代码如下:希望多提意见
```
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        if(matrix == null || matrix.length == 0)
            return res;
        //控制方向的，顺序很重要
        int positions[][] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        int xLen = matrix.length;
        int yLen = matrix[0].length;
        //控制边界的，顺序很重要
        int margin[] = { 0, yLen - 1, xLen - 1, 0 };
        int i = 0, j = 0;
        //控制前进方向的
        int dir = 0;
        while (res.size() < xLen * yLen) {
            res.add(matrix[i][j]);
            i += positions[dir][0];
            j += positions[dir][1];
            if (!((i >= margin[0] && i <= margin[2]) && (j >= margin[3] && j <= margin[1]))) {
                // 到达边界了，更改边界的大小
                margin[dir] = dir == 0 || dir == 3 ? margin[dir] + 1 : margin[dir] - 1;
                i -= positions[dir][0];
                j -= positions[dir][1];
                // 更新前进的方向
                dir = (dir + 1) % 4;
                i += positions[dir][0];
                j += positions[dir][1];
            }
        }
        return res;
    }
}
```
