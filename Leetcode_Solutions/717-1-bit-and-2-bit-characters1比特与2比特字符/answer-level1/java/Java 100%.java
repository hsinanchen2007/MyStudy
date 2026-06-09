### 解题思路
从后向前，递归判别

### 代码

```java
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        return isOneBitCharacter(bits, bits.length - 2);
    }

    private boolean isOneBitCharacter(int[] bits, int i) {
        if (i < 0) return true;

        if (bits[i] == 1) {
            if (i - 1 < 0 || bits[i - 1] != 1) return false;
            else return isOneBitCharacter(bits, i - 2);
        } else
            return isOneBitCharacter(bits, i - 1) || isOneBitCharacter(bits, i - 2);
    }
}
```