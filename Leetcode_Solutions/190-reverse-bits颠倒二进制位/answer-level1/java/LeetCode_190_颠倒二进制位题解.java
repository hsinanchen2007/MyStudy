### 解题思路

类似于之前的字符串翻转问题，将二进制每一位往后移动31 -i的长度即可等于颠倒之后的字符串
题解：
通过数字与1相与拿到数字的每一位二进制，之后通过左移（31 -i）的位置，将该二进制位转为最终位置的十进制表示，并与之前的相加。之后n >> 1，用来拿下一个二进制位

### 代码

```java
public class Solution {
    public int reverseBits(int n) {
       int sum = 0;
        for (int i = 0; i < 32; i++) {
            int tmp = n & 1;
            sum = sum + (tmp << (31 - i));
            n = n >> 1;
        }
        return sum;
    }
}
```