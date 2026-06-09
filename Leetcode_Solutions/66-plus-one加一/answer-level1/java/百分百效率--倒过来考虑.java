### 解题思路
倒过来考虑

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        if (digits.length == 0) {
            return new int[]{1};
        }
        for (int i = digits.length - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i] = digits[i] + 1;
                return digits;
            } else {
                digits[i] = 0;
                if (i == 0) {
                    //到了数组最前面一个数
                    int[] result = new int[digits.length + 1];
                    result[0] = 1;
                    return result;
                }
            }
        }
        return digits;
    }
}
```