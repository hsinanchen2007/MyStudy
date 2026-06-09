### 解题思路
从后往前比较A和B数组中的数字，并放入相应的位置。如果A已放完，那么后面的都放B数组的；如果B已放完，就直接结束，因为所有的操作都在A数组中操作的，之后肯定都是A数组的，不需要再调换位置。

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int index_A = m - 1;
        int index_B = n - 1;
        for (int i = A.length - 1; i >= 0; i--){
            if (index_A < 0){
                A[i] = B[index_B--];
            } else if (index_B < 0){
                break;
            } else {
                A[i] = A[index_A] >= B[index_B] ? A[index_A--] : B[index_B--];
            }
        }
    }
}
```