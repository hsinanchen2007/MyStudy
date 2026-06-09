### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        int res=0,max=0;
        for(int j=0;j<A.length;j++){
           if(max+A[j]-j>res)
           res=max+A[j]-j;
           if(A[j]+j>max)
           max=A[j]+j;
        }
        return res;
    }
}
```