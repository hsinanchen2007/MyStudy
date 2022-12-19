```java
class Solution {
    // 右，下、左、上  
    int[][] dir = { {0, 1},{1,0},{0,-1},{-1,0}};
    public int[] spiralOrder(int[][] matrix) {
        if(matrix == null || matrix.length == 0 || matrix[0].length == 0) return new int[0];
        int left = 0,right = matrix[0].length - 1,top = 0,down = matrix.length - 1;  // 边界
        int d = 0;        // 控制行动方向
        int i = 0,j = -1; //初始位置
        int total = (down + 1) * (right + 1); // 矩阵的数字总数
        int[] res = new int[total];
        int count = 0; //res的index
        while(true){
            i = i + dir[d][0];  j = j + dir[d][1];  // 按照方向前进一格
            if(top <= i && i <= down && left <= j && j <= right){
                //并未越界
                res[count++] = matrix[i][j];
            }else{
                i = i - dir[d][0];  j = j - dir[d][1]; // 越界了，按照原方向要退一格
                if(count >= total)  break; // 得到结果
                // 转换方向  右、下、左、上
                d = (d + 1) % 4;
                if(d == 1) top++; //刚刚向右边走完，所以上边界+1
                else if(d == 2) right--;
                else if(d == 3) down--;
                else if(d == 0) left++;
            }  
        }    
        return res;
    }
}
```
