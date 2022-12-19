执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :40 MB, 在所有 Java 提交中击败了100.00%的用户
### 解题思路
想象下归并排序怎么merge的。
### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int i = m-1 ,j = n-1 ;
        int temp = A.length-1 ; 
        while(i>=0&&j>=0)
        {
            if(A[i]<B[j])
            {
                A[temp--] = B[j--] ;
            }
            else
            {
                A[temp--] = A[i--] ;
            }
        }
        while(j>=0){
            A[temp--] = B[j--] ;
        }
    }
}
```