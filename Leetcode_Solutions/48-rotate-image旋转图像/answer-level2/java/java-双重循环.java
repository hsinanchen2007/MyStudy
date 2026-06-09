### 解题思路
执行用时 0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :38.3 MB, 在所有 Java 提交中击败了5.12%的用户

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for(int i=0; n-2*i > 1; i++){ //第i圈数据个数大于1，才需要交换
            for(int j=i; j<n-1-i; j++){ //若每行n个数，循环结束标志为坐标等于n-2
                swap(matrix,i,j,n);
            }
        }
    }

    // 交换第circle圈（由外向内0->n-1），第num个位置
    private void swap(int[][] matrix, int circle , int num, int n){
        int temp = matrix[circle][num]; //临时存放左上角
        matrix[circle][num] = matrix[n-1-num][circle]; // 左下->左上
        matrix[n-1-num][circle] = matrix[n-1-circle][n-1-num]; //右下->左下
        matrix[n-1-circle][n-1-num] = matrix[num][n-1-circle]; //右上->右下
        matrix[num][n-1-circle] = temp; // 临时单元（原左上）->右上
    }
}
```