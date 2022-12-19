### 解题思路
row[], row[i] : 第i行需要增加的数
col[], col[i] : 第i列需要增加的数
分别统计row[]和col[]
遍历每个行列交叉，判断是否为奇数

### 代码

```java
class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        int [] row = new int[n];
        int [] col = new int[m];
        for(int i = 0; i < indices.length; i++){
            row[indices[i][0]]++;
            col[indices[i][1]]++;
        }
        int count = 0;
        for(int r = 0; r < row.length ; r++){
            for(int c = 0; c < col.length; c++){
                if(((row[r]+col[c])&1) == 1)count ++;
            }
        }
        return count;
    }
}
```