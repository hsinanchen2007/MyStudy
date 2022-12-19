### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        int maxMove = 0;
        Arrays.sort(A);
        for(int i = 1; i < A.length; i++) {
            if(A[i-1]>=A[i]){
                int x = A[i];
                A[i] = A[i-1] +1;
                maxMove += (A[i]-x);
            }
        }
        return maxMove;
    }
}
```