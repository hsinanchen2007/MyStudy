### 解题思路

1.定义一个long型整数
2.使用StringBuilder前判断正负
3.执行转换

### 代码

```java
class Solution {
    public int reverse(int x) {
        String tem = "0";
        long i = x;
        if(i < 0) {
            i = -i;
            tem = "-" + new StringBuilder(i + "").reverse().toString();
        } else {
            tem = new StringBuilder(i + "").reverse().toString();
        }
        i = Long.parseLong(tem);
        if(i > Integer.MAX_VALUE || i < Integer.MIN_VALUE) {
            return 0;
        }
        return (int)i;
    }
}
```