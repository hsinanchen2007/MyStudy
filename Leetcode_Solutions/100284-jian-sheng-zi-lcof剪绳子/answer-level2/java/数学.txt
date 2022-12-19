### 解题思路

 2 = 1 + 1  —— 1 * 1 < 2
 3 = 1 + 2  —— 1 * 2 < 3
 4 = 2 + 2  —— 2 * 2 = 4
 5 = 2 + 3  —— 2 * 3 > 5
 6 = 3 + 3  —— 3 * 3 > 6
 可以知道，分到3和4就好了。再往下分就是越来越小了.(其中3/4 中的2可以分，但是没分，因为分了之后就变得更小了)


### 代码

```java
class Solution {


    public int divideAndMultiply(int n){
        if(n == 3)
            return 3;
        if(n == 4)
            return 4;
        if(n == 5)
            return 6;
        return 3 * divideAndMultiply(n-3);
    }

    public int cuttingRope(int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return 1;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        return divideAndMultiply(n);
    }
}
```