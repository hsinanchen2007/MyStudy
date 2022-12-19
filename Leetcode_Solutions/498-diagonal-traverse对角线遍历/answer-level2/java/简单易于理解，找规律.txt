### 解题思路
 算法思路是:       当遍历对角线的行数为奇数时,是往上走(rows--,col++)
                  当遍历对角线的行数为偶数时候:是往下走(rows++,col--)
                  遍历的总行数是 n=矩阵的行(matrix.length)+矩阵的列(matrix[0].length)-1;
                  当遍历对角线行数为奇数时{r=(i<m)?i:m-1}
                         即当行数超过矩阵的行数时,当前遍历矩阵元素的行就是r=m-1,c=i-r;
                  当遍历对角线行数为偶数时{c=(i<n)?i:n-1}
                        即当行数超过矩阵的列数时,当前遍历矩阵元素的列就是c=n-1,r=i-c;

### 代码

```java
class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        if(matrix==null||matrix.length<1) return new int[0];
        int m=matrix.length,n=matrix[0].length;
        int[] orders = new int[m * n];
        int j=0;
        for(int i=0;i<m+n-1;i++){
            
            int r,c;
            boolean flag=((i+1)&1)==1;
            if(flag){
                r=(i<m)?i:m-1;
                c=i-r;
            }else {
                c=(i<n)?i:n-1;
                r=i-c;
            }
            while (r<m&&r>=0&&c>=0&&c<n){
                orders[j++] = matrix[r][c];
                if(flag){
                    r--;
                    c++;
                }else {
                    r++;
                    c--;
                }
            }

        }
        return orders;
    }
}
```