![捕获.JPG](https://pic.leetcode-cn.com/9388038b64a72fa19fc823eb5e969cc5d4b2150e6b9f9c30988719e4c0ce7618-%E6%8D%95%E8%8E%B7.JPG)

在正序遍历时，把不为0的元素存入队列，
在倒序遍历时，就可以倒序取出，节省时间（不用像官方的那样再次挨个遍历）。

```
class Solution {
    public int[][] updateMatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] out = new int[m][n];
        LinkedList<Integer> st = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <n ; j++) {
                if(matrix[i][j]==0){
                    out[i][j] = 0;
                }else{
                    out[i][j] = m+n;
                    st.add(i*n+j);
                    if(i>0) out[i][j] = Math.min(out[i][j],out[i-1][j]+1);
                    if(j>0) out[i][j] = Math.min(out[i][j],out[i][j-1]+1);
                }

            }

        }
        while(!st.isEmpty()){
            int num = st.removeLast();
            int i = num/n;
            int j =num%n;
            if(i<m-1) out[i][j] = Math.min(out[i][j],out[i+1][j]+1);
            if(j<n-1) out[i][j] = Math.min(out[i][j],out[i][j+1]+1);
        }
        return out;
    }
}
```

