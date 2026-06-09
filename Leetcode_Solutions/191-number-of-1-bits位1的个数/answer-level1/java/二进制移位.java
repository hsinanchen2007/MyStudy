### 解题思路
简单的二进制移位操作

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        //位1的个数
        int ans = 0;
        while (n != 0) {
            if ((n & 1) == 1) {
                ans +=1;
            }
            n = n >>> 1;
        }
        return ans;
    }
}
```