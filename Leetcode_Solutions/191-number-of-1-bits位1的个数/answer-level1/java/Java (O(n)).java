### 解题思路
掩码设定为1，然后不断左移一位，变成10,100,1000。
每次跟掩码比较，不等于0代表掩码的最高位对应的n的位置为1。

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count = 0;
        int mask = 1; // 1, 10, 100, 1000 ... 
        for (int i = 0; i < 32; i++){
            // 每次跟掩码比较，不等于0代表掩码的最高位对应的n的位置为1。
            if ((n & mask) != 0){
                count++;
            }
            mask <<= 1;
        }
        return count;
    }
}
```