设置界限，模拟顺时针路径
```
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        int m = matrix.length;
        if(m==0){
            return new int[]{};
        }
        int n = matrix[0].length;
        int top = 0, bot = m-1, left = 0, right = n-1;      //设置上下左右界限
        int cnt = 0;
        int[] res = new int[m*n];

        while(top<=bot&&left<=right){                       //遍历matrix
            for(int j=left;j<=right;j++){                   //从左到右
                res[cnt++] = matrix[top][j];
            }
            top++;
            for(int i=top;i<=bot;i++){                      //从上到下
                res[cnt++] = matrix[i][right];
            }
            right--;
            for(int j=right;j>=left&&top<=bot;j--){         //从右到左
                res[cnt++] = matrix[bot][j];
            }
            bot--;
            for(int i=bot;i>=top&&left<=right;i--){         //从下到上
                res[cnt++] = matrix[i][left];
            }
            left++;
        }
        return res;
    }
}
```
