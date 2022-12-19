### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int hammingDistance(int x, int y) {
        int i=x^y;
        i = i - ((i >>> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
        i = (i + (i >>> 4)) & 0x0f0f0f0f;
        i = i + (i >>> 8);
        i = i + (i >>> 16);
        return i & 0x3f;
    }
}
```