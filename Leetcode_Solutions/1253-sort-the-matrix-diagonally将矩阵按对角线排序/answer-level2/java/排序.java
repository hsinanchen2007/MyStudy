### 解题思路
emmm，就是一条一条对角线排过去

### 代码

```java
class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int row = mat.length;
        int col = mat[0].length;
        for (int j = 0; j < col; j++) {
            List<Integer> l = new ArrayList<>();
            int temp = j;
            int i = 0;
            while (i < row && j < col) {
                l.add(mat[i][j]);
                i++;
                j++;
            }
            Collections.sort(l);
            i = 0;
            j = temp;
            while (i < row && j < col) {
                mat[i][j] = l.get(i);
                i++;
                j++;
            }
            j = temp;
        }
        for (int i = 1; i < row; i++) {
            List<Integer> l = new ArrayList<>();
            int temp = i;
            int j = 0;
            while (i < row && j < col) {
                l.add(mat[i][j]);
                i++;
                j++;
            }
            Collections.sort(l);
            i = temp;
            j = 0;
            while (i < row && j < col) {
                mat[i][j] = l.get(j);
                i++;
                j++;
            }
            i = temp;
        }
        return mat;
    }
}
```