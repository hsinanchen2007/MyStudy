### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        if (digits[len - 1] < 9) {
            digits[len - 1] += 1;
            return digits;
        }
        boolean flag = true;
        for (int i = len - 1; i >= 0 ; i--) {
            if (flag) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                    flag = true;
                } else {
                    digits[i] += 1;
                    flag = false;
                }
            } else {
                break;
            }
        }
        if (digits[0] == 0) {
            int[] newDigits = new int[len + 1];
            newDigits[0] = 1;
            System.arraycopy(newDigits, 0, digits, 0, len);
            return newDigits;
        }
        return digits;
    }
}
```