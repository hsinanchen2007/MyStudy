### 解题思路

在处理这类整数类型的二进制的题目的时候，要学会使用处理字符串那样的思路，一位一位的去处理数字中的bit。

题目中要求求出数字的二进制中1的个数。

要每次去一个数字中的一个位数，可以使用下列方法

```java

while(n != 0) {
    bitN = n & 1;
    // do someting
    n = n >>> 1; // Java中没有无符号数，所以我使用右移补0的这种操作，其他语言可用>>来右移
}

```

之后入门就可以在do something的地方做文章了。文中是要我们算出1的个数，所以我们只要把位数加起来，就是二进制中1的个数了。

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int tmp = 0;
        while (n != 0) {
            tmp += n & 1;
            n = n >>> 1;
        }
        return tmp;
    }
}
```