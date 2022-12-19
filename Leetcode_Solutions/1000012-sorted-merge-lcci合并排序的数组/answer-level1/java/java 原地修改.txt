从后向前比较，大的数放到最后的位置
```
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int i = m-1,j=n-1;
        int k = 1;
        while(i>=0&&j>=0){
            if(A[i] < B[j]){
                A[m+n-k] = B[j];
                j--;
            }else{
                A[m+n-k] = A[i];
                i--;
            }
             k++;
        }
        if(i<0){
            for(int t = j;t>=0;t--){
                A[t] = B[t];
            }
        }

        
    }
}
```
