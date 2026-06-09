[github](https://github.com/BlackNiuza/WritingForOffer/blob/master/leetcode-cn/daily2020/_892_%E4%B8%89%E7%BB%B4%E5%BD%A2%E4%BD%93%E7%9A%84%E8%A1%A8%E9%9D%A2%E7%A7%AF.java)

package daily2020;

public class _892_三维形体的表面积 {

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.surfaceArea(new int[][]{{2}}));
        System.out.println(s.surfaceArea(new int[][]{{1, 2}, {3, 4}}));
        System.out.println(s.surfaceArea(new int[][]{{1, 0}, {0, 2}}));
        System.out.println(s.surfaceArea(new int[][]{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}));
        System.out.println(s.surfaceArea(new int[][]{{2, 2, 2}, {2, 1, 2}, {2, 2, 2}}));
    }

    static class Solution {
        public int surfaceArea(int[][] grid) {
            int maxX = grid.length;
            int maxY = grid.length;
            int[][][] a = new int[maxX + 1][][];
            int[][] maxZ = new int[maxX + 1][];
            for (int x = 1; x <= maxX; x++) {
                a[x] = new int[maxY + 1][];
                maxZ[x] = new int[maxY + 1];
                for (int y = 1; y <= maxY; y++) {
                    maxZ[x][y] = grid[x - 1][y - 1];
                    a[x][y] = new int[maxZ[x][y] + 1];
                    for (int z = 1; z <= maxZ[x][y]; z++) {
                        a[x][y][z] = 1;
                    }
                }
            }

            int dirLen = 6;
            int[] dirX = {0, 0, 0, 0, 1, -1};
            int[] dirY = {0, 0, 1, -1, 0, 0};
            int[] dirZ = {1, -1, 0, 0, 0, 0};

            int res = 0;
            for (int x = 1; x <= maxX; x++) {
                for (int y = 1; y <= maxY; y++) {
                    for (int z = 1; z <= maxZ[x][y]; z++) {
                        if (a[x][y][z] == 0) {
                            continue;
                        }
                        for (int d = 0; d < dirLen; d++) {
                            int newX = x + dirX[d];
                            int newY = y + dirY[d];
                            int newZ = z + dirZ[d];
                            if (
                                    0 ==newX|| newX> maxX
                                            || 0 == newY|| newY > maxY
                                            || 0 == newZ|| newZ > maxZ[newX][newY]
                                            || 0 == a[newX][newY][newZ]
                            ) {
                                res++;
                            }
                        }
                    }
                }
            }
            return res;
        }
    }

}