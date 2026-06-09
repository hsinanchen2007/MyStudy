### 解题思路
- 深度优先遍历，判断终止条件
- 将遍历过的进行标记，符合条件的标记为true
- 可以达到的+1，然后再选择四个方向进行遍历

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        boolean[][] matrix = new boolean[m][n];// 移动的矩阵
        return move(0,0,matrix,k);
    }

    public int  move(int x,int y,boolean[][] matrix,int k){
        if (x <0 || x >= matrix.length || y < 0 || y >=matrix[0].length ||(x/10 + x % 10 + y/10+y%10) > k || matrix[x][y]) return 0;
        matrix[x][y] = true;

        return 1 + move(x+1,y,matrix,k) +
                move(x-1,y,matrix,k)+
                move(x,y+1,matrix,k)+
                move(x+1,y-1,matrix,k);

    }
}
```