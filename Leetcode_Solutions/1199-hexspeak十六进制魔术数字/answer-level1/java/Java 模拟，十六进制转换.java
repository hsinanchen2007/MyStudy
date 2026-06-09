
采用直接转换为数字，再模拟十六进制转换的方式。
十六进制相当于二进制每四位重新表示，因此可以使用位运算 `& 15` 方式取余（相当于 `% 16`）。

题解：
```java
class Solution {
    public String toHexspeak(String num) {
        long value = Long.valueOf(num), modValue;
        String ret = "";
        
        while(value != 0) {
            modValue = value & 15;
            if (modValue == 0) ret = "O" + ret;
            else if (modValue == 1) ret = "I" + ret;
            else if (modValue >= 10) ret = (char)('A' + modValue - 10) + ret;
            else return "ERROR";

            value >>= 4;
        }
        return ret;
    }
}
```

**补充：**

下面是一些转换 16 进制的库做法，仅供参考，面试可以提这些方法，但做题还是要老老实实做：
  1. `long Long.parseLong(String s, int radix)`
  2. `String Long.toHexString(long i)` Link: [Java Lightning Speed and Clean Solution 100%](https://leetcode.com/problems/hexspeak/discuss/440866/Java-Lightning-Speed-and-Clean-Solution-100)



目前来看本题的解法都是直接转换为数字，有兴趣的可以研究一下 JDK 的 `Long.parseLong(String s, int radix)` 方法如何将字符串直接转换为十六进制的值，加以改造应该也许可以实现更快的解答。
