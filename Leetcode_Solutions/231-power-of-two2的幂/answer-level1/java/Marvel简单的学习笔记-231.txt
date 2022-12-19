### 1ms，消除最低位的1
若一个数为2的幂，则它的二进制码中有且只有一位为1，那么将这个1消掉后，该数将变为0；若该数不是2的幂，上述操作后，该数不为0。
消去1的方法：
一个数n与(n-1)做按位与，可消去n的二进制码中最低位的1。
可参考Marvel简单的学习笔记-191。

### 代码

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n <= 0)  return false;
        int t = n & (n - 1);
        return t == 0;
    }
}
```