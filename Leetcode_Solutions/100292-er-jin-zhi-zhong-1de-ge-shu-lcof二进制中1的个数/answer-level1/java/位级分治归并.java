### 解题思路
普通的用一个1移位遍历的方法就不说了。利用分治的思想，将32位数先分成32组，那么每一组中的该位的值就是改组的1的个数，将32个组两两合并，获得16个长度为2的组；然后继续两两组的值合并，获得8个长度为4的组；之后可以继续两两合并下去，但节省步骤就直接将这四组一次性合并了。

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        // 1 -> 2，16组
        int util = 0x55555555;
        n = (n & util) + ((n >> 1) & util);
        // 2 -> 4, 8组
        util = 0x33333333;
        n = (n & util) + ((n >> 2) & util);
        // 4 -> 8, 4组
        util = 0x0f0f0f0f;
        n = (n & util) + ((n >> 4) & util);
        // 4组一次性合并
        return ((n & 0xff) + ((n >> 8) & 0xff) + (n >> 16) & 0xff) + ((n >> 24) & 0xff);
    }
}
```