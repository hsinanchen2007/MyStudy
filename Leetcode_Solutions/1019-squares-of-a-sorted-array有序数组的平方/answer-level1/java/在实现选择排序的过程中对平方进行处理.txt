挺慢的
```
class Solution {
    public int[] sortedSquares(int[] A) {
        if(A == null || A.length < 1) return A;
        // Selection sort 
        for(int i = 0; i < A.length; i++){
            int min = i;
            for(int j = i + 1; j < A.length; j++){
                if(Math.abs(A[j]) < Math.abs(A[min])){
                    min = j;
                }
            }
            if(i == min){
                A[i] = A[i] * A[i];
            }else{
                int temp = A[i];
                A[i] = A[min] * A[min];
                A[min] = temp;
            }
        }
        return A;
    }
}
```
