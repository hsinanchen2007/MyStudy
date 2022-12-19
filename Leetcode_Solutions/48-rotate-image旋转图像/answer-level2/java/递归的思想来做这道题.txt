我们观察每一层的翻转过程，发现都是一样的过程。
所有可以将问题逐渐拆解和扩展。
```
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length - 1;
        slove(matrix,0,n);
    }
    private void slove(int[][] matrix,int start,int end){
        if(end - start <= 0) return;
        int n = end - start;
        for(int i = 0; i < n; i++){
            int tmp = matrix[start][start+i];
            matrix[start][start+i] = matrix[n-i+start][start];
            matrix[n-i+start][start] = matrix[n+start][n-i+start];
            matrix[n+start][n-i+start] = matrix[i+start][n+start];
            matrix[i+start][n+start] = tmp;
        }
        slove(matrix,start+1,end-1);
    }
}
```