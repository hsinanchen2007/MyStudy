### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<List<String>> finalList = new ArrayList<List<String>>();
    public List<List<String>> solveNQueens(int n) {
        int[] rec = new int[n];
        List<String> list = new ArrayList<String>();
        dfs(0, rec, list,n);
        return finalList;
    }
    public void dfs(int row, int[] rec, List<String> list,int n) {
        if (row == n) {
            Object clone = ((ArrayList<String>) list).clone();
            finalList.add((List<String>) clone);
            return;
        }
        for (int col = 0; col < n; col++) {
            boolean ok = true;
            for (int j = 0; j < row; j++) {
                if (rec[j] == col || row + col == j + rec[j] || row - col == j - rec[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                char[] chars = new char[n];
                Arrays.fill(chars, '.');
                chars[col] = 'Q';
                list.add(new String(chars));
                rec[row] = col;
                dfs(row + 1, rec, list,n);
                rec[row] = 0;
                list.remove(row);
            }
        }
    }
}
```