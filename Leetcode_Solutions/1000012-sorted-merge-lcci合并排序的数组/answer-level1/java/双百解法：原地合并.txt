### 解题思路
总共元素个数为 m+n，而A空间足够，那么可知无论怎么合并，最大的元素位置位于 A[m+n-1] 处。

为了在合并时不覆盖A中元素，因此考虑从后向前扫描合并，那么可知不论A或B谁长，都可以正常合并不至于覆盖。

透过m,n，直接定义出A,B以及合并之后的元素索引号，在扫描合并时就无需考虑越界问题，直接采用后置减直到0即可。

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int i = m-1;
        int j = n-1;
        int z = m+n-1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) {
                A[z--] = A[i--];
            } else {
                A[z--] = B[j--];
            }
        }

        while (j >= 0) {//只处理B剩余的部分
            A[z--] = B[j--];
        }
    }
}
```