1、BFS的过程中，记录每个皇后的位置和结果。
2、回溯，如果下一行没有一个可以摆放皇后的位置，那么需求删掉第一步记录的位置和结果，然后再次BFS
```
class Solution {
public static List<List<String>> solveNQueens(int n) {
    //DFS搜索，回溯
    Map<Integer, List<Integer>> posi = new HashMap<>();
    List<List<String>> res = new ArrayList<>();
    List<String> one = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      cal(n, 0, i, res, posi, one);
      one.clear();
    }
    return res;

  }

  public static boolean cal(int n, int row, int col, List<List<String>> res,
      Map<Integer, List<Integer>> posi, List<String> oneRow) {

    //剪支，不能和前面的点，同行，同列，同对角线
    for (int j = 0; j < row; j++) {
      int rowT = posi.get(j).get(0);
      int colT = posi.get(j).get(1);
      if (col == colT || (Math.abs((row - rowT) / (col - colT)) == 1
          && (row - rowT) % (col - colT) == 0)) {
        return false;
      }
    }

    List<Integer> node = new ArrayList<>();
    node.add(row);
    node.add(col);
    posi.put(row, node);
    StringBuilder sb = new StringBuilder();
    for (int k = 0; k < n; k++) {
      if (k == col) {
        sb.append("Q");
      } else {
        sb.append(".");
      }
    }
    oneRow.add(sb.toString());

    if (row == n - 1) {
      List<String> one = new ArrayList<>(oneRow);
      res.add(one);
    }
    //记录这一层的点有没有可以摆放皇后的位置
    boolean flag = false;
    for (int i = 0; i < n; i++) {
      if (cal(n, row + 1, i, res, posi, oneRow)) {
        flag = true;
      }
    }

    //没有的话，需要删掉上层已经记录的皇后位置
    if (!flag) {
      posi.remove(row);
      oneRow.remove(oneRow.size() - 1);
    }
    return flag;

  }

}
```
