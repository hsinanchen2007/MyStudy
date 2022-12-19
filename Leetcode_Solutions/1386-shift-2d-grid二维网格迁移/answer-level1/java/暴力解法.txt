class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int row = grid.length;
        int col = grid[0].length;
        int[] cols = new int[row];
        //移动k次
        while (k-- > 0) {
            //记录二位数组最后一列的值
            for(int i = 0 ;i < row ;i++) {
                cols[i] = grid[i][col -1 ];
            }
            //将二维数组的列向右移动一位
            for(int i = row - 1 ;i >= 0 ; i--) {
                for(int j = col -1 ;j  > 0 ;j--) {
                    grid[i][j] =grid[i][j - 1];
                }
            }
            //将之前记录最后一列的值赋给第一列
            //第一个值为最后一列的最后一行的值，其他顺序
            grid[0][0] = cols[cols.length - 1];
            for(int i = 0;i < cols.length - 1 ;i ++) {
                grid[i + 1][0] = cols[i];
            }
        }
        将结果返回
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        List<Integer> help = new ArrayList<>();
        for(int i = 0; i < row ;i ++) {
            for (int j = 0 ;j < col ;j++ ) {
                list.add(Integer.valueOf(grid[i][j]));
            }
            res.add(new ArrayList<>(list));
            list.clear();

        }
        return res;
    }
}