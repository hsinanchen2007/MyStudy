### 解题思路
更加简洁的动态规划思想

### 代码

```java
import java.lang.Math;
class Solution {
    public int cuttingRope(int n) {
        if(n==2){return 1;}
        if(n==3){return 2;}
        int[] result = new int[n+1];
        result[0] = 0;
        result[1] = 1;
        result[2] = 2;
        result[3] = 3;
        for(int i =4;i<=n;i++){
            int a = result[i-2]*2;
            int b = result[i-3]*3;
            result[i] = Math.max(a,b);
        }
        return result[n];
    }
}
```