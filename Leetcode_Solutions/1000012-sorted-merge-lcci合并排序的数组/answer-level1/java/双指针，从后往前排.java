1. 俩个数组分别用俩个指针从后往前比较
2. 在A数组中指定第三个指针（俩个数组之和）
3. 将比较好的值放到第三个指针去，从后往前赋值。


class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int k = m + n - 1 , i = m - 1 , j = n - 1 ;
        while( i >= 0 && j >= 0){
            if(A[i] < B[j]){
                A[k--] = B[j--];
            }else{
                A[k--] = A[i--];
            }
        }
        while(j >= 0){
            A[k--] = B[j--];
        }
    }
}