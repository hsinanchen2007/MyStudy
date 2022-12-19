### 解题思路
- 直接利用A数组，倒序进行归并操作。归并操作完成后，如果A中还有元素未被扫描完毕，直接不用管，其在A数组中的顺序本来就是正确的；如果B中有元素未被扫描完毕，依次倒着放入A中即可。

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int i = m - 1;  //i指向A中最大元素
        int j = n - 1;  //j指向B中最大元素
        int k = m + n - 1;

        while ( i >= 0 && j >= 0) {
            if (A[i] >= B[j])   A[k--] = A[i--];
            else    A[k--] = B[j--];
        }

        while ( j >= 0 )    //B中剩下元素归位到A中
            A[k--] = B[j--];
    }
}
```