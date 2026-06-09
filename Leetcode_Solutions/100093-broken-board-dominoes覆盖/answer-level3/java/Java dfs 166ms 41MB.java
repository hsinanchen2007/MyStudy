### 解题思路
由于mn都小于8，可以使用9m+n来代替某一个点，之后就是dfs回溯，最后的边界坑死我了，努力提高自己把。

### 代码

```java
import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int domino(int n, int m, int[][] broken) {
        if (broken.length == 0) {
			return n * m >> 1;
		}
        Set<Integer> set = new HashSet<>();
        for (int[] i : broken) {
            set.add(9*i[0]+i[1]);
        }
        dfs(0, 0, m, n, set);
        return this.max;
    }
    int res = 0;
    int max = 0;

    private void dfs(int i, int j, int row, int col, Set<Integer> set){
        if (i>=col-1&&j>=row-1) {
            return;
        }
        if (i>=col){
            dfs(0, j + 1, row, col, set);
            return;
        }
        if (set.contains(9*i+j)){
            dfs(i + 1, j, row, col, set);
            return;
        }
        if (i<col-1&&!set.contains(9*(i+1)+j)){
            res++;
            max = Math.max(res, max);
            set.add(9*(i+1)+j);
            set.add(9*i+j);
            dfs(i + 2, j, row, col, set);
            set.remove(9*(i+1)+j);
            set.remove(9*i+j);
            res--;
        }
        if (j<row-1&&!set.contains(9*i+j+1)){
            res++;
            max = Math.max(res, max);
            set.add(9*i+j+1);
            set.add(9*i+j);
            dfs(i+1, j, row, col, set);
            set.remove(9*i+j+1);
            set.remove(9*i+j);
            res--;
        }
        
        if ((set.contains(9*(i+1)+j)&&set.contains(9*i+j+1))){
            dfs(i + 2, j, row, col, set);
        }
        if (((j==row-1)&&set.contains(9*(i+1)+j))){
            dfs(i + 2, j, row, col, set);
        }
        if (((i==col-1)&&set.contains(9*i+j+1))){
            dfs(0, j+1, row, col, set);
        }
    }
}
```