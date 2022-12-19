### 解题思路
上面
tmp=top;top = left
右边
tmp2=right;right=tmp;
下面
tmp=bottom;bottom=tmp2;
左边
left=tmp


### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        if (n == 0) return;
        int levels = n/2;
        for (int l=0;l<=levels;l++) {
            int[] tmp = new int[n];
            int[] tmp2 = new int[n];
            //top = left 从最右边开始 逆序
            for (int i=n-l-1;i>=l;i--){
                tmp[i] = matrix[l][i]; //2,1
                matrix[l][i] = matrix[n-i-1][l];//3,1
            }
            //3,1
            for (int i=n-l-1;i>=l+1;i--){
                tmp2[i] = matrix[i][n-l-1];
                matrix[i][n-l-1] = tmp[i];
            }
            // bottom = right 逆序
            for (int i=l;i<n-l-1;i++) {
                tmp[i] = matrix[n-l-1][i];
                matrix[n-l-1][i] = tmp2[n-i-1];
            }
            // left = baktop 顺序
            for (int i=l+1;i<n-l-1;i++) {
                matrix[i][l] = tmp[i];
            }
        }

    }
}
```