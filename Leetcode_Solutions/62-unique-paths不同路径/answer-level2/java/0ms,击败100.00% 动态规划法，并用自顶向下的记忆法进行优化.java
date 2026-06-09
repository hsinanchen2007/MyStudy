### 解题思路
每个方格的路径数等于它的上方和左方路径数之和

### 代码

```java
class Solution {
    int [][] mem;
    public int uniquePaths(int m, int n) {
        mem = new int[m][n];
        mem[0][0] = 1;
        return recursive(m - 1, n - 1);
    }
    public int recursive(int x, int y) {
        if (x == 0 && y == 0) {
            return 1;
        }
        int res = 0;
        if (x > 0 && y >= 0) {
            if (mem[x - 1][y] == 0) {
                mem[x - 1][y] = recursive(x - 1, y);
            }
            res += mem[x - 1][y];   
        }
        if (y > 0 && x >= 0) {
            if (mem[x][y - 1] == 0) {
                mem[x][y - 1] = recursive(x, y - 1);
            }
            res += mem[x][y - 1]; 
        }
        return res;

    }
}
```