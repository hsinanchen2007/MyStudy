水平反转就是左右两个指针left、right交换元素；

反转图片表示1变为0和0变为1，可以A[i][j] = 1 - A[i][j] 来表示反转;

另外交换和反转可以同时完成。
```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for(int i = 0; i < A.length; i++){
            int left = 0; 
            int right = A[0].length-1;
            while(left < right){
                int temp = A[i][left];
                A[i][left] = 1 - A[i][right];
                A[i][right] = 1 - temp;
                left++;
                right--;
            }
            if(left == right) A[i][left] = 1 - A[i][left];
        }
        return A;
    }
}
```