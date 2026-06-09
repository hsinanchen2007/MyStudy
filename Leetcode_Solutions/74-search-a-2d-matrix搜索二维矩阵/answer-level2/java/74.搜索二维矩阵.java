100%  70%
先找所在的可能行，再找所在的可能列，若行列所在的值等于target，则返回true,若最终没找到，则返回false。
```
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix.length == 0 || matrix[0].length == 0)  return false;
       int m = matrix.length;          //矩阵行数
       int n = matrix[0].length;       //矩阵列数
        //求所在行
        int leftr = 0;
        int rightr = m - 1;
        while(leftr < rightr){
            int midr = leftr + (rightr - leftr + 1)/2;      //左边界不动，为了避免死循环，取右中位数
            if(matrix[midr][0] > target){
                rightr = midr - 1;
            }else{
                leftr = midr;           //左边界不动
            }
        }
        //得到的leftr（rightr）就是要求的所在行
        //求所在列
        int leftc = 0;
        int rightc = n - 1;
        while(leftc < rightc){
            int midc = leftc + (rightc - leftc + 1)/2;
            if(matrix[leftr][midc] > target){
                rightc = midc - 1;
            }else{
                leftc = midc;
            }
        }
        if(matrix[leftr][leftc] == target)    return true;
        else   return false;
    }
}
```