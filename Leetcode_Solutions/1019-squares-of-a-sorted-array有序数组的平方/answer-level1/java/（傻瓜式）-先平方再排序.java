```
class Solution {
    public int[] sortedSquares(int[] A) {
        for(int i=0;i<A.length;i++){
            A[i]=A[i]*A[i];
        }
        for(int i=0;i<A.length-1;i++){
            for(int j=0;j<A.length-i-1;j++){
                if(A[j]>A[j+1]){
                    int temp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = temp;
                }
            
            }
        }
        return A;
    }
}
```
