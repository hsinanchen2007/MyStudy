### 解题思路
利用递归的方法, BFS

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        int[][] table = new int[m][n];
        return clab(table, 0,0, k);
    }

    private int clab(int[][] table, int m, int n, int k) {
        if (m < 0 || n < 0|| m >= table.length || n>= table[0].length || table[m][n] != 0 || !count(m,n,k)) {
            if (m >= 0 && n >= 0 && m < table.length && n < table[0].length) {
                table[m][n] = 1;
            }
            return 0;
        }
        table[m][n] = 1;
        return 1+clab(table,m+1,n,k)+clab(table,m,n+1,k);
        
    }

    public boolean count(int m, int n, int k) {
        int count = 0;
        for (;m>0; m/=10) {
            count += m%10;
        }
        for (;n>0; n/=10) {
            count += n%10;
        }
        return count <= k;
    }
}
```