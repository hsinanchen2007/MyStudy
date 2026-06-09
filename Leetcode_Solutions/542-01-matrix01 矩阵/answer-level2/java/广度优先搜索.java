### 解题思路
此处撰写解题思路
这题主要的想法是先保存住某个位置为0的下标，将不是0的位置初始化为一个大的数，比如行数+列数的和是不可能达到的。需要一个方向矩阵，上下左右移动，将为0位置保存到一个队列里，满足一行一行遍历，对这些位置进行上下左右移动，如果移动后的位置是最大值，则将此位置的值进行更新并加入队列。
### 代码

```java
class Solution {
    public int[][] updateMatrix(int[][] matrix) {
        int row = matrix.length;
        int column = matrix[0].length;
        Queue<int[]> queue = new LinkedList<>();
        int[][] vectors = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(matrix[i][j] == 0)
                    queue.add(new int[]{i,j});
                else
                    matrix[i][j] = row + column;
            }
        }


        while(!queue.isEmpty()){
            int[] mat = queue.poll();
            for(int[] vec : vectors){
                int r = mat[0] + vec[0];
                int c = mat[1] + vec[1];
                if(r >= 0 && r < row && c >= 0 && c < column){
                    if(matrix[r][c] >= matrix[mat[0]][mat[1]]+1){
                        matrix[r][c] = matrix[mat[0]][mat[1]]+1;
                        queue.add(new int[]{r,c});
                    }
                }
            }
        }
        return matrix;
    }

    
}
```