### 解题思路
将A[i] + A[j] + i - j拆分成第j个点的 A[j]-j加上这个点之前的max(A[i]+i)

### 代码

```java
class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        int min1 = A[0]-0;
        int max1 = A[1]+1-A[0];
        for(int i=1;i<A.length;i++){
            max1=Math.max(max1,A[i]-i+min1);
            min1=Math.max(min1,A[i]+i);
        }
        return max1;
    }
}
```