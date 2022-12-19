### 解题思路
简单三指针

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int index=m+n-1;
        int a=m-1,b=n-1;
        while (a>=0 || b>=0){
            if (a>=0 && b>=0){
                if (A[a]>=B[b])
                    A[index--]=A[a--];
                else
                    A[index--]=B[b--];
            }
            else if (a>=0)
                A[index--]=A[a--];
            else
                A[index--]=B[b--];
        }
    }
}
```