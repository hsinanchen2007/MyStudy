### 解题思路
每个int型数存储32位。根据给定的宽度，计算出需要移动哪个int型数的哪几位，将相应的位置1，仅4行代码。

### 代码

```java
class Solution {
    public int[] drawLine(int length, int w, int x1, int x2, int y) {
        int[] store = new int[length];
        int fromBit = y * w + x1, toBit = y * w + x2;
        for (int i = fromBit; i <= toBit; i ++) store[i / 32] |= 1 << (31 - i % 32);
        return store;
    }
}
```