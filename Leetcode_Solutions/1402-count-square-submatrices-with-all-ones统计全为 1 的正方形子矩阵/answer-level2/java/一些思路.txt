### 解题思路
其实就是遍历问题，在遍历的时候我们可以知道，每一个数 matrix[i][j] 是由它的 matrix[i-1][j] 、 matrix[i][j-1] 和 matrix[i-1]][j-1] 决定的，其实挺好想的，顺便在遍历的时候计数，应该还有更好的办法。
![image.png](https://pic.leetcode-cn.com/aa777fca4914cac183be25f44acc1067ac2460a3195ad332c00d8c2bbf91fc9c-image.png)

### 代码

```java
class Solution {
    public int countSquares(int[][] matrix) {
        int m = matrix.length ;
        int n = matrix[0].length ;
        int res = 0;
        for(int i = 0 ;i < m;i++){
            for(int j = 0;j< n;j++){
                if(i==0 || j==0){
                    res += matrix[i][j]; 
                    continue;
                }
                if (matrix[i-1][j-1] * matrix[i][j-1] * matrix[i-1][j] * matrix[i][j]>0  ){
                    matrix[i][j] = min(matrix[i-1][j-1],matrix[i][j-1],matrix[i-1][j])+1;
                }
                res += matrix[i][j];
            }
        }
        return res;
    }
    int min(int a, int b, int c){
        if(a>b){
            if(c>=b) return b;
            else return c;
        }
        else{
            if(c>=a) return a;
            else return c;
        }
    }
    
}
```