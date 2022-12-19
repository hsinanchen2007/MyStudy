### 解题思路
正向遍历计算和，如果和为负数，则舍弃这段数据。如果满足要求则计算下标距离，但是还需要从当前下标反向遍历一次，和刚刚的最小下标距离作比较，取较小的哪那一个。

### 代码

```java
class Solution {
    public int shortestSubarray(int[] A, int K) {
         int len = A.length;
        int sum=0;
        int minLen=0;
        int x=0;
        for (int i=0;i<len;i++){
            if (A[i]>=K){
                return 1;
            }
            sum+=A[i];
            if (sum<=0){
               x=i+1;
               sum=0;
               continue;
            }
            if (sum>=K){
                if (minLen==0){
                    minLen= i-x+1;
                }else {
                    minLen = Math.min(minLen, i - x + 1);
                }
                int tSum=0;
               for (int j=i;j>x;j--){
                   tSum=tSum+A[j];
                   if (tSum>=K){
                       minLen=Math.min(minLen,i-j+1);
                       tSum=0;
                       break;
                   }
               }
            }
        }
        if (minLen==0){
            return -1;
        }
        return minLen;
    }
}
```