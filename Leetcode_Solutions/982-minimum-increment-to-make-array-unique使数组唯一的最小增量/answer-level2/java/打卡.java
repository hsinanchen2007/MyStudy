### 解题思路
暴力解

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        Arrays.sort(A);
        int ret = 0;
        for(int i = 1;i < A.length;i++){
            while(A[i] <= A[i-1]){
                A[i]++;
                ret++;
            }
        }
        return ret;
    }
}
```