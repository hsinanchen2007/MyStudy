```
class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(n, new LinkedList<Integer>(), result );
        List<List<String>> lists = new ArrayList<>();
        for (List<Integer> e : result) {
            List<String> list = new ArrayList<>();
            lists.add(list);
            for (int i = 0; i < n; i++) {
                int y = e.get(i);
                StringBuilder sb = new StringBuilder(n);
                for (int j = 0; j < n; j++ ) {
                    sb.append(j == y ? "Q" : ".");
                }
                list.add(sb.toString());
            }
            
        }
        return lists;
    }

    void backtrack(int n, LinkedList<Integer> col, List<List<Integer>> result) {
        if (col.size() == n) {
            result.add(new ArrayList<>(col));
            return;
        } else {
            for (int i = 0; i < n; i++) {
                boolean ok = true;
                int current_x = col.size();
                int current_y = i;
                int x = 0;
                for (int y : col) {
                    if (y == current_y
                    ||Math.abs(current_x - x) == Math.abs(current_y - y)) {
                        ok = false;
                        break;
                    } 
                    x++; 
                }
                if (ok) { 
                    col.add(i);
                    backtrack(n, col, result);
                    col.removeLast();
                }
            }
        }
    }
}
```
