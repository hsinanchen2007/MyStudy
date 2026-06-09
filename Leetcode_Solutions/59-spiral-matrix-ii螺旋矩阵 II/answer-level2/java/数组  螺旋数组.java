### 解题思路
分段处理

### 代码

```java
class Solution {
    public int[][] generateMatrix(int n) {
int[][] matrix=new int[n][n];
int num=1;
for(int i=0;i<n;i++){
for(int j=i;j<n-i;j++){
    matrix[i][j]=num;
    num++;
    if(num>n*n){
        return matrix;
    }
} 
for(int m=i+1;m<n-i;m++){
    matrix[m][n-i-1]=num;
    num++;
    if(num>n*n){
        return matrix;
    }
}  
for(int x=n-i-2;x>i-1;x--) {
    matrix[n-i-1][x]=num;
    num++;
    if(num>n*n){
        return matrix;
    }
}
for(int y=n-i-2;y>i;y--){
    matrix[y][i]=num;
    num++;
    if(num>n*n){
        return matrix;
    }
}
}
return matrix;
    }
}
```