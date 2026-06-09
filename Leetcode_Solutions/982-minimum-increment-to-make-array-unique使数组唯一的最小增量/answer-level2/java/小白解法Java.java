### 解题思路
知乎：god-jiang
CSDN：god-jiang

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        Arrays.sort(A);
        int move=0;
        for(int i=1;i<A.length;i++){
            if(A[i]<=A[i-1]){
                int pre=A[i];
                A[i]=A[i-1]+1;
                move+=A[i]-pre;
            }
        }
        return move;
    }
}
```