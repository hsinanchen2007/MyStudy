### 解题思路
合并排序是把两个有序的集合合并成一个有序的集合。
每次比较集合中较小的一个放到新数组中，直到一个集合走到了末尾。
把剩下那个集合的元素放到新数组的末尾。

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int i = 0;
        int j = 0;
        int k = 0;
        int l = m + n;
        int[] result = new int[l];
        if(m > 0 && n > 0) {
            for(; k < m+n; k++) {
                if(A[i] <= B[j]) {
                    result[k] = A[i];
                    i++;
                    if(i == m) {
                        break;
                    }
                } else {
                    result[k] = B[j];
                    j++;
                    if(j == n) {
                        break;
                    }
                }
            }
            k++;
       }
        if(i == m && n > 0) {
           for(;k < l; k++) {
               result[k] = B[j];
               j++;
           }
       }
       if(j == n && m > 0) {
           for(;k < l; k++) {
               result[k] = A[i];
               i++;
           }
       }
       for(int a = 0; a < l ; a++) {
           A[a] = result[a];
       }
    }
}
```