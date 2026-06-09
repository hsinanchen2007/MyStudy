// 遍历奇数位，只要是偶数，就把这个数和偶数应该在的位置交换，由于交换来的数也可能是偶数所以要用while循环，直到当前i位位奇数为止

```
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        if(null == A || A.length == 0){
            return A;
        }
        int p = 0;
        for(int i = 1; i < A.length && p < A.length; i = i + 2){
            while(A[i] % 2 == 0){
                if(i == p){
                    p = p + 2;
                }else{
                    int temp = A[i];
                    A[i] = A[p];
                    A[p] = temp;
                    p = p + 2;
                }
            }
        }
        return A;
    }
}
```
