### 解题思路
因为A的长度大于B的长度，且A的长度有富余，所以针对A从后往前推，可以直接将A改变为需要的数组。

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int k=m+n-1,i=m-1,j=n-1;
        while(i>=0 && j>=0){
            if(A[i]<B[j]){
                A[k--]=B[j--];
            }else{
                A[k--]=A[i--];
            }
        }
        while(j>=0){
            A[k--]= B[j--];
        }
    }
}
```