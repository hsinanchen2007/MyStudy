```
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();

        if(matrix.length == 0)
            return res;

        int m = matrix.length;
        int n = matrix[0].length;
        int top = 0;
        int left = 0;

        while(top < m && left < n){
            if(top < m){
                for(int i = left; i < n; i++)
                    res.add(matrix[top][i]);
                top++;
            }

            if(left < n){
                for(int i = top; i < m; i++)
                    res.add(matrix[i][n-1]);
                n--;
            }

            if(top < m){
                for(int i = n-1; i >= left; i--)
                    res.add(matrix[m-1][i]);
                m--;
            }

            if(left < n){
                for(int i = m-1; i >= top; i--)
                    res.add(matrix[i][left]);
                left++;
            }
        }

        return res;
    }
}
```
