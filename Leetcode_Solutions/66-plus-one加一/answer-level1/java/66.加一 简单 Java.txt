### 解题思路
本题关键点在于判断是否有进位，并且还有特殊情况需要额外处理（全为9）的时候，需要开设一个新数组，一开始没看懂为什么直接new一个长度加一的数组然后0下标位置1就可以，后来想清楚了，要增加一位的情况，也就只有全是9的情况了。还有一个关键操作就是取余数%10，这样直接保留个位，并根据个位情况确定是否需要进位。
这里说明一下在java和C++中%代表取余数，是向0取整，而在python中%代表取模运算，是向负无穷取整，两者只在对负数运算中有不同，正数运算中一致。

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        for(int i = digits.length - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] %= 10;
            if(digits[i] != 0)
                return digits;
        }
        digits = new int[digits.length + 1];
        digits[0] = 1;
        return digits;
    }
}
```