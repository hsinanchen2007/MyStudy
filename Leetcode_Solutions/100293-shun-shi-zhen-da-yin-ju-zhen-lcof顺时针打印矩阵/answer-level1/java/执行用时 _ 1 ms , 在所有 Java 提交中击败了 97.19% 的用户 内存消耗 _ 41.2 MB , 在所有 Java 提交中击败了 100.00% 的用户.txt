### 解题思路
说实话很讨厌做这种考验逻辑思维的题目，脑子转不过来就完了

### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if(matrix.length==0) return new int[0];
        int a = 0,b = matrix.length-1,c=0,d=matrix[0].length-1,count=0;
        int[] arr = new int[(b+1)*(d+1)];
        while(true) {
            for(int j = c;j<=d;j++) arr[count++] = matrix[a][j];
            if(++a>b) break;
            for(int i = a;i<=b;i++) arr[count++] = matrix[i][d];
            if(--d<c) break;
            for(int j = d;j>=c;j--) arr[count++] = matrix[b][j];
            if(--b<a) break;
            for(int i = b;i>=a;i--) arr[count++] = matrix[i][c];
            if(++c>d) break;
        }
        return arr;

    }
}


```