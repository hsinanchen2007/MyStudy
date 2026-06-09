### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        if(A==null||A.length==0)
            return 0;
        int max=0;
        int preMax=A[0]+0;
        for(int i=1;i<A.length;i++){
            max=Math.max(max,preMax+A[i]-i);
            preMax=Math.max(preMax,A[i]+i);
        }
        return max;
    }
}
```