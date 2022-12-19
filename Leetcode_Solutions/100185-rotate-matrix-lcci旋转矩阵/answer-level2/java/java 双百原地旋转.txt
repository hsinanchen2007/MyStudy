### 解题思路
此处撰写解题思路
首先理解这道问题，将整个数组顺时针旋转90度，形成新的数组，首先以一个点(0,0)为例，旋转之后，点的坐标，可以表示，为了节省空间，需要将这个点关联的四个点同时旋转，才可以做到节省空间。所以暂定每次都进行四个点的交换，之后再寻找点交换之间的规律
发现以点旋转为例，可以将整个矩阵分成四个大块。
横向分就以长度一半，
纵向根据长度奇偶性，来分画成图应该是：
```
o o o x x x 
o o o x x x
o o o x x x
x x x x x x 
x x x x x x
x x x x x x
```
既所有的x都可以被o经过旋转得到。
之后，就以o标注的点为例，进行循环，寻找在四处的规律完成整个矩阵旋转

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int len = matrix.length-1;
        int x = matrix.length/2;
        int y =0;
        if(matrix.length%2 == 0){
            y = x;
        }else{
            y = x+1;
        }
        
        for(int i = 0;i<x;i++){
            for(int j = 0;j<y;j++){
               int a = matrix[0+j][len-i];
               matrix[j][len-i] = matrix[i][j];
               int b = matrix[len-i][len-j];
               matrix[len-i][len-j] = a;
               matrix[i][j] = matrix[len-j][i];
               matrix[len-j][i] = b;
            }
        }
    }
}
```