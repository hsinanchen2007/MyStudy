```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int l = 0;
        int r = A.length-1;

        //分成四种情况考虑
        while(l<=r) {
            if(A[l] % 2 == 0 && A[r] % 2 != 0) {
                l++;
                r--;
            }else if(A[l] % 2 == 0 && A[r] % 2 == 0) {
                l++;
            }else if(A[l] % 2 != 0 && A[r] % 2 == 0){
                int temp = A[l];
                A[l] = A[r];
                A[r] = temp;
                l++;
                r--;
            }else {
                r--;
            }
        }

        return A;
    }
}
```
