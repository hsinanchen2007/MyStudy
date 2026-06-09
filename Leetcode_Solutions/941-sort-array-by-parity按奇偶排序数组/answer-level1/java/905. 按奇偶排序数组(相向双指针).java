采用双指针（two pointer）的方法，一个从头开始，一个从尾开始，头指针定位到从前到后的第一个奇数，尾指针定位到从后到前的第一个偶数，两者交换即可
```java []
class Solution {
    public int[] sortArrayByParity(int[] A) {
        if(A.length == 0){
            return A;
        }
        
        int start  = 0, end = A.length - 1;
        while(start < end){
            while(start < end && A[start] % 2 == 0){
                start++;
            }
            while(start < end && A[end] % 2 == 1){
                end--;
            }
            if(start < end){
                int temp;
                temp = A[start];
                A[start] = A[end];
                A[end] = temp;
                start++;
                end--;
            }
        }
        return A;
    }
}
```
