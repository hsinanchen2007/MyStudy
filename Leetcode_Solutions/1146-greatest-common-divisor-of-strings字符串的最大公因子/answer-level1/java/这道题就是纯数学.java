### 解题思路
（1）正反拼接，要是不相等，肯定没有。
（2）取两个字符串长度的最大公约数，然后截取最大公约数的长度即可。

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }
        
        return str1.substring(0, gcd(str1.length(), str2.length()));
    }

    private int gcd(int m, int n) {
        while (m != n) {
            if (m > n) {
                m -= n;
            } else {
                n -= m;
            }
        }
        
        return m;
    }
}
```