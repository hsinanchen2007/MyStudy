### 解题思路
n = n & (n-1) 将二进制n中的最右边的1去掉。

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count = 0;
        while(n != 0){
            n = n & (n-1);
            count += 1;
        }
        return count;
    }
}
```