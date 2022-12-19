### 解题思路
借用 HashMap 的 tableSizeFor 方法，结果减1后得到低位全是1的数。
最后，& 运算获得结果

### 代码

```java
class Solution {
    public int findComplement(int num) {
        return ~num & (tableSizeFor(num)-1);
    }

    int tableSizeFor(int cap) {
        int n = cap - 1;
        n |= n >>> 1;
        n |= n >>> 2;
        n |= n >>> 4;
        n |= n >>> 8;
        n |= n >>> 16;
    return (n < 0) ? 1 : (n >= 1 << 30) ? 1 << 30 : n + 1;
    }
}
```
