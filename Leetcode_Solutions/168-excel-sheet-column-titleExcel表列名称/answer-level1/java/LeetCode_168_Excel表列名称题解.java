### 解题思路

这道题目其实就是求解26进制的题目。

1 = A 
2 = B
3 = C
.
28 = AB
.
.
701 = ZY

这道题目很想二进制，但是二进制是[0, 1]表示的。这道题目里面没有0，我们使用的数组是[1, 26]，所以在计算时要将数字-1来匹配我们数组中的数字。



### 代码

```java
class Solution {
    private final static String TMP = "ZABCDEFGHIJKLMNOPQRSTUVWXY";

    public String convertToTitle(int n) {
        StringBuilder end = new StringBuilder();

        for (int i = n; i > 0; i = (i - 1) / 26) {
            end.insert(0, TMP.charAt(i % 26));
        }

        return end.toString();
    }
}
```