### 解题思路
(int)Math.pow(2, i) 当Math.pow(2, i) 大于int可以表达的范围的时候，取最大值了。
所以需要做特殊处理，将特殊的过滤出去。

### 代码

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        //(int)Math.pow() 超过了范围就按照最大的数就保留最大，比如(int)2^32 = 2^32 - 1
        int i;
        for(i = 0; (int)Math.pow(2, i) < n; i++);
        if(i > 1 && (int)Math.pow(2, i) % 2 != 0)    
            return false;
        return (int)Math.pow(2, i) == n;
    }
}
```