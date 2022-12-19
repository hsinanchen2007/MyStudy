### 解题思路

灵感来自插入排序，将数组B中的每个数插入到A中。

取B的每一个数与A中的数比较，从A的最后一个数开始比较，如果B中的数小于A中的数，则将A的数后移给B留出一个插入位置，直到满足B的数大于A的数，就可以直接插入到当前位置。以此类推，将B中所有数插入到A中。

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        for(int i = 0; i < n; i++){
            int b = B[i];
            int j = m - 1 + i;

            while(j >= 0 && b <= A[j]){
                A[j+1] = A[j];
                j--;
            }

            A[j+1] = b;
        }
    }
}
```