### 解题思路

每四位二进制等于一位十六进制，第一思想肯定是先把数字转成二进制数组，之后再进行每四位转译为一位十六进制，但是这样会存在负数，符号位的问题，而且`-2147483648`这个用例存在转正溢出啊 = =，只要使用取巧的方式，每次与`0xf`相与，取出最低四位，之后数字无符号左移四位，循环拼接字符串。

经过这道题目，可以看出想要拿到数字的二进制低位，只需要与要转换的进制最后一个数字相与，之后循环即可。

例如每次拿十进制的最后一个二进制

```java
while(num != 0) {
    int low = num & 1;
    num = num >>> 1;
}
```

拿十进制的最低四位

```java
while(num!=0) {
    int low = num & 0xf;
    num = num >>> 4;
}
```

其他进制也是一样的思路。

### 代码

```java
class Solution {
    private final static String[] hex = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};

    public String toHex(int num) {
        if (num >= 0 && num < 16) return hex[num];
        int tmp = 0xf;

        StringBuilder sb = new StringBuilder();
        while (num != 0) {
            int low = num & tmp;
            num = num >>> 4;
            sb.insert(0, hex[low]);
        }
        return sb.toString();
    }
}
```