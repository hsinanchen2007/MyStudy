### 解题思路
每次都选择数量最多的字符，然后append 两个该字符，如果append两个字符之后的数量仍大于排名第二的字符，就append一个排名第二的字符。

当排名第二的字符是0个的时候，append min(2, 第一个字符的剩余数量)

### 代码

```java
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        return generate(a, b, c, "a", "b", "c");
    }

    String generate(int a, int b , int c , String aa, String bb, String cc) {
        if (a < b) {
            return generate(b, a, c, bb, aa, cc);
        }
        if (a < c) {
            return generate(c, b, a, cc, bb, aa);
        }
        if (b < c) {
            return generate(a, c, b, aa, cc, bb);
        }
        if (b == 0) {
            return aa.repeat(Math.min(2, a));
        }
        int use_a = Math.min(2, a);
        int use_b = a - use_a >= b ? 1 : 0;
        return aa.repeat(use_a) + bb.repeat(use_b) + generate(a - use_a, b - use_b, c, aa, bb, cc);
    }
}
```