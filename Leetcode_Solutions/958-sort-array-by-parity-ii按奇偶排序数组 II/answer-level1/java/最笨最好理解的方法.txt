定义两个指针index1和index2，分别记录偶数和奇数对应位置的为元素，每次各加2，并把奇偶排序后的结果存在B中。

```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int[] B = new int[A.length];
        int index1 = 0, index2 = 1;
        for(int i = 0; i < A.length; i++){
            if(A[i] % 2 == 0){ // A中出现偶数
                B[index1] = A[i];
                index1 += 2; // 偶数索引指针更新
            }else{ // A中出现奇数
                B[index2] = A[i];
                index2 += 2; // 奇数索引指针更新
            }
        }
        return B;
    }
}
```