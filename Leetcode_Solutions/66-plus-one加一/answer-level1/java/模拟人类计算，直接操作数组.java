### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int index = digits.length - 1;
        while (index >= 0) {
            digits[index] = digits[index] + 1;
            if (digits[index] > 9) {
                digits[index] = 0;
                index --;
            } else {
                index = -2;
            }
        }
        // 进位，增加一位，其余所有位都会是0
        if (index == -1) {
            int[] ans = new int[digits.length + 1];
            ans[0] = 1;
            return ans;
        } else {
            return digits;
        }
    }
}
```