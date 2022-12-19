方法一：左右各一个指针遍历并交换。

1. 左奇右偶，则交换并移动左右指针；
2. 左奇右奇，则向左移动右指针；
3. 左偶右偶，则向右移动左指针；
4. 左偶右奇，则直接移动左右指针。

```java
class Solution {
    public int[] sortArrayByParity(int[] A){
        int left = 0;
        int right = A.length - 1;
        while(left < right){
            if(A[left] % 2 == 1 && A[right] % 2 == 0){
                int temp = A[left];
                A[left] = A[right];
                A[right] = temp;
                left++;
                right--;
            }else if(A[left] % 2 == 1){
                right--;
            }else if(A[right] % 2 == 0){
                left++;
            }else{
                left++;
                right--;
            }
        }
        return A;
    }
}
```

方法二：另外开辟一个A.length大小的空间B，遍历A遇到偶数从左边插入，遇到奇数从右边插入。

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int[] B = new int[A.length];
        int index1 = 0, index2 = A.length-1;
        for(int i = 0; i < A.length; i++){
            if(A[i] % 2 == 0){
                B[index1++] = A[i];
            }else{
                B[index2--] = A[i];
            }
        }
        return B;
    }
}
```