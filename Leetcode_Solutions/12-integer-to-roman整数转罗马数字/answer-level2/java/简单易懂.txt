### 解题思路

先装大石头，再装小石子，最后是沙子，直至装满。

### 代码

```java
class Solution {
    private static final String[] ROME_CHAR = {"I", "IV", "V", "IX", "X", "XL", "L",
            "XC", "C", "CD", "D", "CM", "M"
    };

    private static final int[] ROME_VALUE = {1, 4, 5, 9, 10, 40, 50, 90, 100,
            400, 500, 900, 1000
    };
    public String intToRoman(int num) {
        StringBuilder builder = new StringBuilder();
        for (int i = ROME_CHAR.length - 1; i >= 0; i--) {
            while (num >= ROME_VALUE[i]) {
                num -= ROME_VALUE[i];
                builder.append(ROME_CHAR[i]);
            }
        }
        return builder.toString();
    }
}
```