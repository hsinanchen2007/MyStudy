### 解题思路
指针法的应用

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        
        int i=0;
        int j=0;
        while(i+j<A.length && i<m && j<n){
            if(A[m-1-i]>B[n-1-j]){
                A[A.length-1-i-j] = A[m-1-i];
                i++;
            }else{
                A[A.length-1-i-j] = B[n-1-j];
                j++;
            } 
        }
        while(i<m){A[A.length-1-i-j] = A[m-1-i]; i++;}
        while(j<n){A[A.length-1-i-j] = B[n-1-j]; j++;}
            
    }
}
```