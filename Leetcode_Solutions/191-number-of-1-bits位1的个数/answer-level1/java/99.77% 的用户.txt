### 解题思路
既然是无符号整数，那就遍历32次，时间、空间复杂度都是O(1)，n>>(31-i) & 1)获取最右边那一位，然后判断是否等于1

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count = 0;
        for(int i=31; i>=0; i--){
            count += (n>>(31-i) & 1) == 1 ? 1 : 0;
        }
        return count;
    }
}
```