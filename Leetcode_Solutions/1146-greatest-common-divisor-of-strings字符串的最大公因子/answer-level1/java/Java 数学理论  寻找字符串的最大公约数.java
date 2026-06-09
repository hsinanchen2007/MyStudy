### 解题思路
看了官方题解写的代码。
重点已经在注释中，拿几个例子分析下就明白啦。

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        // 如果str1和str2调整顺序拼接之后的字符串相同，则一定存在“最大公约数”子串
        // 反之一定不存在则返回空字符串即可
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }

        int length1 = str1.length();
        int length2 = str2.length();

        // 求得最大公约数即子串的长度！！！
        int index = gcd(length1, length2);
        // 根据index获取对应的子串即可！！！
        return str1.substring(0, index);
    }

    // Greatest common divisor 最大公约数
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a%b);
    }
}
```