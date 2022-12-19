### 解题思路
最高票的java版本

### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ret = new ArrayList();
        if (matrix == null) return null;
        if (matrix.length < 1 || matrix[0].length < 1 ) return ret;
        int s = 0;
        int z = 0;
        int y = matrix[0].length - 1; //二维数组，第一个是大的几个数组  第二个是子数组；
        int x = matrix.length - 1;
        
        while(true) {
            for (int i=z; i<=y; i++) {
                ret.add(matrix[s][i]);
            }
            if(++s > x) break;
            for (int i=s; i<=x; i++) {
                ret.add(matrix[i][y]);
            }
            if(--y < z) break;
            for (int i=y; i>=z; i--) {
                ret.add(matrix[x][i]);
            }
            if(--x < s) break;
            for (int i = x; i>=s; i--) {
                ret.add(matrix[i][z]);  
            }
            if(++z > y) break;
        }
        return ret;
    }
}
```