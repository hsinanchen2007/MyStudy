### 解题思路
    反着来，从A数组末尾开始往前赋值，比较A、B数组中的值，将大的值放进A的末尾。

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        if(B==null || A==null){
            return;
        }
        int i,j,k;
        for(i=m-1,j=n-1,k=m+n-1;i>=0&&j>=0&&k>=0;){
            if(A[i]<=B[j]){
                A[k--]=B[j--];
            }else{
                A[k--]=A[i--];
            }
        }
        while(i>=0){
            A[k--]=A[i--];
        }
        while(j>=0){
            A[k--]=B[j--];
        }
    }
}
```