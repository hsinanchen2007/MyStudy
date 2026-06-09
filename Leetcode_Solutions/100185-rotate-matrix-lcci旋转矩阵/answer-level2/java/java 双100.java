### 解题思路
逐层逐点旋转
难点在于分析没个点旋转后的位置，可以取四个角旋转来梳理思路，然后推广到一般点的旋转。
### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int N=matrix.length-1;
        int total=(matrix.length)>>1;
        int x=0;
        while(x<total){
            //逐层旋转
            //左上 (x,x)    右上(x,N-x)
            //左下 (N-x,x)  右下（N-x,N-x）
            for(int i=x;i<N-x;i++){
                int tmp=matrix[x][i];
                matrix[x][i]=matrix[N-i][x];
                matrix[N-i][x]=matrix[N-x][N-i];
                matrix[N-x][N-i]=matrix[i][N-x];
                matrix[i][N-x]=tmp;
            }
            x++;
        }
    }
}
```