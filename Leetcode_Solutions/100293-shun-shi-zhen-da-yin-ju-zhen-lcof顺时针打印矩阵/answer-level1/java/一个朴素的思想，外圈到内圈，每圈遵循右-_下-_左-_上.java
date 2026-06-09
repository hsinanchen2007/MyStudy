### 解题思路
此处撰写解题思路
每一圈从外向内打印，从左上角(0,0)开始遵循右->下->左->上的思路，每次移动判断是否坐标是否溢出和坐标是否被占用，并设置一个matri一样大占用标志数组，标志每个数是否被占用，内圈打印时需要这个标志位来判断的，不然会重复打印。
如何遍历所有的圈呢？从左上角，更里面的一圈为i+1,j+1，一直向里，直到坐标被占用
### 代码

```java
class Solution {
    private int[][] matrix;
    public int[] spiralOrder(int[][] matrix) {
        if(matrix.length == 0){
            return new int[0];
        }
        this.matrix = matrix;
        int[] res = new int[matrix.length*matrix[0].length];
        boolean[][] occupyFlag = new boolean[matrix.length][matrix[0].length];
        int resPointer = 0;
        int startI = 0, startJ = 0;
        while(isLegal(startI, startJ) && !occupyFlag[startI][startJ]){
            int i = startI,j=startJ;
            //右
            while(isLegal(i, j) && !occupyFlag[i][j]){
                res[resPointer++] = matrix[i][j];
                occupyFlag[i][j] = true;
                j++;
            }
            //下
            j--;
            i++;
            while(isLegal(i, j) && !occupyFlag[i][j]){
                res[resPointer++] = matrix[i][j];
                occupyFlag[i][j] = true;
                i++;
            }
            //左
            i--;
            j--;
            while(isLegal(i, j) && !occupyFlag[i][j]){
                res[resPointer++] = matrix[i][j];
                occupyFlag[i][j] = true;
                j--;
            }
            //上
            j++;
            i--;
            while(isLegal(i, j) && !occupyFlag[i][j]){
                res[resPointer++] = matrix[i][j];
                occupyFlag[i][j] = true;
                i--;
            }
            startI++;
            startJ++;
        }
        return res;
        
    }
    public boolean isLegal(int i, int j){
        return i>=0 && i<matrix.length && j>=0 && j<matrix[0].length;
    }
}
```