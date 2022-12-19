### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        // 是否进位
        boolean up = true;
        // 倒序遍历
        for (int i = digits.length - 1; i >= 0; i--) {
            if (up) {
                digits[i] = ++digits[i] % 10;
                if (digits[i] != 0) {
                    return digits;
                }
            } else {
                return digits;
            }
        }
        if (up) {
            int[] res = new int[digits.length +1];
            res[0] = 1;
            return res;
        }
        return digits;
    }
}
```