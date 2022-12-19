### 解题思路
进位 加1，后面变0 的思想

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        for (int i = len - 1; i >= 0 ; i--){
            digits[i]++;
            if (digits[i] % 10 != 0) return digits;
            digits[i] = 0;
        }
        digits = new int[len + 1];
        digits[0] = 1;
        return digits;

    }
}
```
PS:借鉴YHHZW 的解法，自己加深印象。