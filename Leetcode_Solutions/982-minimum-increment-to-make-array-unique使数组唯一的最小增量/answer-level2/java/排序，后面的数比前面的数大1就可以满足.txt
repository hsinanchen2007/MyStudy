### 解题思路
排序，后面的数比前面的数大1就可以满足

### 代码

```java
class Solution {
    public  int minIncrementForUnique(int[] A) {
        Arrays.sort(A);
        int result=0;
        for(int i=1;i<A.length;i++){
            if(A[i]<=A[i-1]){
                int pre=A[i];
                A[i]=A[i-1]+1;
                result=result+A[i]-pre;
            }
        }
        return result;
    }
}
```