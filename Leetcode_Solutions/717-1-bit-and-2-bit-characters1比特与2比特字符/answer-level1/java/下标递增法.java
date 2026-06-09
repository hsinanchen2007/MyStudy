### 解题思路 从左到右遍历数组，如果是1，则下标加2，如果是0，则下标加1，最终下标=bits.length-1 ,则说明是符合预期的，末尾是0
### 代码

```java
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
          int i = 0;
        while (i < bits.length - 1) {
            if (bits[i] == 0) {
                i++;
            } else if (bits[i] == 1) {
                i += 2;
            }
        }

        if (i == bits.length - 1) {
            return true;
        }

        return false;
    }
}
```