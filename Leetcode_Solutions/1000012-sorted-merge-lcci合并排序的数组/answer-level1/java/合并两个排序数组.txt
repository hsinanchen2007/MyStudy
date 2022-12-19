### 解题思路

### 代码

```java
class Solution {

 public void merge(int[] A, int m, int[] B, int n) {
       while(m>0&&n>0){
            //注意这里的执行顺序m-- - 1:先执行m-1操作，而后执行自减操作
           A[m+n-1]=A[m-1]>B[n-1]?A[m-- - 1]:B[n-- - 1];
       }
       //此时m=0,A原来里面的m个元素已经被排好
       while(n>0){
           A[n-1]=B[n-1];
           n--;
       }
 }

    
}
```