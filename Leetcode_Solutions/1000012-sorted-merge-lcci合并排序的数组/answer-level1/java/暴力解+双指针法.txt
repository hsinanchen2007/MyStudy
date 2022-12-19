**暴力解**
### 解题思路
将数组 $B$ 赋值到数组 $A$ 的后半部分，然后对数组 $A$ 进行排序。
时间复杂度：$O((m+n)log(m+n))$
空间复杂度：$O(m+n)$

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int j = 0;
        for(int i = m;i<m+n;i++){
            A[i] = B[j++];
        }
        Arrays.sort(A);
    }
}
```

**双指针法**
### 解题思路
将数组 $A$ 中的值保存到辅助数组中，辅助数组和 $B$ 数组用各自指针分开来对比，始终取较小值
任一数组未比较完的部分，直接赋值给 $A$ 数组。

时间复杂度：$O(m+n)$
空间复杂度：$O(m+n)$

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int[] help = new int[m];
        for (int i = 0;i<m;i++){
            help[i] = A[i];
        }
        int i = 0;
        int j = 0;
        int k = 0;
        while (i<m&&j<n){
            while (i<m&&j<n&&help[i]<=B[j]){
                A[k++] = help[i++];
            }
            
            while (i<m&&j<n&&B[j]<=help[i]){
                A[k++] = B[j++];
            }
        }

        while (i<m){
            A[k++] = help[i++];
        }
        while (j<n){
            A[k++] = B[j++];
        }
    }
}
```