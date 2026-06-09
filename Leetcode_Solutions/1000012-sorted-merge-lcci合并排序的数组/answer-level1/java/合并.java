### 解题思路
打卡打卡

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int aflag = m-1 ,bflag = n-1,t = n+m-1;
        while(aflag >= 0 && bflag >= 0){
            if(B[bflag] >= A[aflag]){
                A[t] = B[bflag--];
            }else{
                A[t] = A[aflag--];
            }
            t--;
        }
        while(bflag >= 0){
            A[t--] = B[bflag--];
        }
    }
}
```