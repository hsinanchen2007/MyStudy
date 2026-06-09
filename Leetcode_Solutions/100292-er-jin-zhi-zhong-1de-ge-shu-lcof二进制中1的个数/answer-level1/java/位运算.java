### 解题思路
解法1：按位做与运算并右移直到 n = 0;
解法2：n & (n - 1) 等价于将 n 最右边的 1 转为 0;

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        /*
        int count = 0;
        while (n != 0) {
            count += n & 1;
            n >>>= 1;
        }
        return count;
        */

        int count = 0;
        while(n != 0){
            n = n & (n - 1);
            count++;
        }
        return count;
    }
}
```