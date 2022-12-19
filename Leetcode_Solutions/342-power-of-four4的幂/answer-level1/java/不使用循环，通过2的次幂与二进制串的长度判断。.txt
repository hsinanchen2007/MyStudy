### 解题思路
发现新大陆，熏弟们进来看看

### 代码

```java
class Solution {
    public boolean isPowerOfFour(int num) {
        if (num < 1) return false;
        // 是4的幂次方一定是2的幂次方，2的幂次方二进制表示上只有一个1
        boolean isPowerOf2 = (num & num - 1) == 0;
        // 如果是4的幂，二进制串的长度一定是奇数。 因为4的次幂总是在2的幂基础上隔一个数比如  16是 32 不是 64是
        int blen = Integer.toBinaryString(num).length();
        return isPowerOf2 && (blen & 1) == 1;
    }
}
```