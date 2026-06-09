### 解题思路


### 代码

```java
class Solution {
    public int[] sumZero(int n) {
        int[] ret = new int[n];
        if(n == 1) {
            ret[0] = 0;
            return ret;
        }
        int sum = 0;
        if(n > 1) {
            for(int i = 0; i < n-1; i++) {
                ret[i] = i;
                sum = sum + ret[i];
            }
            ret[n-1] = -sum;
        }
        return ret;
    }
}
```