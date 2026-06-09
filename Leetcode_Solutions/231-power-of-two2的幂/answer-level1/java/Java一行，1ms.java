执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :33.6 MB, 在所有 Java 提交中击败了45.58%的用户

### 解题思路
用Integer类内置函数检测二进制里有几个1，只有一个则为true

### 代码

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        return n>0 && Integer.bitCount(n) == 1;
    }
}
```