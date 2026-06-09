```
class Solution {
    public String tictactoe(int[][] moves) {
        boolean[] xCount = new boolean[10];
        boolean[] oCount = new boolean[10];

        // 将每个棋子放到对应的位置，用于统计是否胜利
        for (int i = 0; i < moves.length; i++) {
            if (i % 2 == 0) {
                xCount[moves[i][0] * 3 + moves[i][1] + 1] = true;
            } else {
                oCount[moves[i][0] * 3 + moves[i][1] + 1] = true;
            }
        }
        if (isSuccess(xCount)) {
            return "A";
        }
        if (isSuccess(oCount)) {
            return "B";
        }
        return moves.length == 9 ? "Draw" : "Pending";
    }

    /**
     * 判断是否胜利
     *
     * @param count
     * @return
     */
    private boolean isSuccess(boolean[] count) {
        // 胜利的 8 种情况
        int[][] successes = {{1, 2, 3}, {1, 4, 7}, {1, 5, 9}, {2, 5, 8},
                {3, 6, 9}, {3, 5, 7}, {4, 5, 6}, {7, 8, 9}};

        for (int[] success : successes) {
            if (count[success[0]] && count[success[1]] && count[success[2]]) {
                return true;
            }
        }
        return false;
    }
}
```