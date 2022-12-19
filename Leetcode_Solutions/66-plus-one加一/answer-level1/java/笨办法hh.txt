### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int count = 0;
        for (int i = digits.length - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
                count++;
            } else {
                digits[i] = digits[i] + 1;
                break;
            }
        }
        // 全部为 9 的情况 {9} {9,9} {9,9,9}
        int[] fdigits = new int[digits.length + 1];
        if (count == digits.length) {
            for (int i = 0; i < fdigits.length; i++) {
                if (i == 0) {
                    fdigits[i] = 1;
                } else {
                    fdigits[i] = 0;
                }
            }
            return fdigits;
        }
        return digits;
    }
}
```