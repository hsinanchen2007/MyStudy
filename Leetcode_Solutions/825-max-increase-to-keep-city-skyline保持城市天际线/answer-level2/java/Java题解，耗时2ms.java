#### *`java`*获得从上往下看的最大天际线和从下左往右看的最大天际线，然后计算差的和就行了
```
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int size = grid.length;
        int[] arr1 = new int[size];
        int[] arr2 = new int[size];
        int sum = 0;
        for (int i = 0; i < size; i++) {//获得每一行和每一列的最大值，储存到arr1 和arr2中
            int xmax = -1;
            int ymax = -1;
            for (int j = 0; j < size; j++) {
                if (grid[i][j] > ymax) {//能将i和j互换的前提也是这个二维数组长宽相等 即grid.length = grid[0].length
                    ymax = grid[i][j];
                    arr1[i] = ymax;
                }
                if (grid[j][i] > xmax) {
                    xmax = grid[j][i];
                    arr2[i] = xmax;
                }
            }
        }
        for (int i = 0; i < size; i++) {//计算每个元素与最大值的差之和
            for (int j = 0; j < size; j++) {
                sum += Math.min(arr1[i], arr2[j]) - grid[i][j];
            }
        }
        return sum;
    }
}
```
