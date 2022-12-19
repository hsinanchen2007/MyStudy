### 解题思路
大数相加，传统艺能。用时0ms

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int flag = 1;
        int cur = 0;
        for (int i = digits.length - 1; i >= 0; i--){
            cur = digits[i] + flag;
            digits[i] = cur % 10;
            flag = cur / 10;
        }
        if (flag > 0){
            int[] result = new int[digits.length + 1];
            result[0] = flag;
            System.arraycopy(digits, 0, result, 1, digits.length);
            return result;
        }else {
            return digits;
        }
    }
}
```