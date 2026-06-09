class Solution {
    public static List<String> list = new ArrayList(){{
        add("294753618");
        add("816357492");
        add("672159834");
        add("492357816");
        add("276951438");
        add("618753294");
        add("834159672");
        add("438951276");
    }};

    public int numMagicSquaresInside(int[][] grid) {
        int col = grid[0].length;
        int row = grid.length;
        int sum = 0;
        if (row < 3 || col < 3) {
            return 0;
        }
        for (int i = 1; i < row - 1; i ++) {
            for (int j = 1; j < col - 1; j ++) {
                boolean b = calc(grid, i, j);
                if (b) {
                    sum += 1;
                }
            }
        }
        return sum;
    }

    public static boolean calc(int[][] arr, int i, int j) {
        StringBuilder sb = new StringBuilder();
        sb.append(arr[i-1][j-1]).append(arr[i-1][j]).append(arr[i-1][j+1]).append(arr[i][j-1])
                .append(arr[i][j]).append(arr[i][j+1]).append(arr[i+1][j-1]).append(arr[i+1][j]).append(arr[i+1][j+1]);
        if (list.contains(sb.toString())) {
            return true;
        }
        return false;
    }

    
}