### 解题思路
使用两个指针，a，b
因为A中有足够的空间，可以在原地进行修改
从后往前使用归并排序
1. a = m -1; b = n -1; index = A.length -1;
2. a索引的值比b索引的值小的时候，那么在A的index处填入A[a],a--,index--;
3. 反之，在A的index出填入B[b],b--,index--;
4. 注意，要考虑到原A，B数组已经遍历完的情况，即：a == -1 || b == -1,那么直接的将没遍历完的数组中的值赋予A就可以了

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int index = A.length - 1;
        int a = m -1;
        int b = n - 1;
        while(index >= 0){
            if(a == -1 && b >= 0){
                A[index--] = B[b--];
            }
            else if(b == -1 && a >= 0){
                A[index--] = A[a--];
            }
            else if(A[a] < B[b]){
                A[index--] = B[b--];
            }
            else{
                A[index--] = A[a--];
            }
        }
    }
}
```