```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        /*
        遍历二维数组的每一行，对每一行的数组采用双指针法
        如果两个指针指向的元素相同，就没必要交换了，只需要将其从0变1，从1变0就可，
        这里采用异或操作，1^1=0, 1^0=1。若果两个指针指向的元素不相同比如0,1，交换后变成1,0，
        替换后又变成0,1，所以两元素相同就不用任何操作了。
        
        */
        int rows = A.length;
        int columns = A[0].length;
        
        for (int i = 0; i < rows; i++){
            int left = 0, right = columns - 1;
            while (left < right){
                if(A[i][left] == A[i][right]){
                    A[i][left] ^= 1;
                    A[i][right] ^= 1;
                }
                left++;
                right--;
            }
            if(left == right){
                A[i][left] ^= 1;
            }
        }
        
        return A;
    }
}
```