### 解题思路
第一遍，找到正负交界，找的同时把负数反转，方便比较，
然后从中间开始把数组 分为两个有序的递增数组， 进行归并

### 代码

```java
class Solution {
    public int[] sortedSquares(int[] A) {
        int[] result = new int[A.length];
        int plus = 0;
        while(plus < A.length && A[plus] < 0){
            A[plus] = - A[plus];
            plus++;
        }
        int minus = plus - 1;
        int idx = 0;
        while(minus >= 0 && plus < A.length){
            if(A[minus] < A[plus]){
                result[idx++] = A[minus] * A[minus];
                minus--;
            }else {
                result[idx++] = A[plus] * A[plus];
                plus++;
            }
        }
        while(minus >= 0){
            result[idx++] = A[minus] * A[minus];
                minus--;
        }
        while(plus < A.length){
            result[idx++] = A[plus] * A[plus];
            plus++;
        }
        return result;
    }
}
```