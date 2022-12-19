### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
         for (int i = digits.length - 1; i >= 0; i--) {
            if(++digits[i] == 10){
                digits[i] = 0;
            } else {
                return  digits;
            }
        }
        digits = new int[digits.length + 1];
        digits[0] = 1;
        return digits;
    }
}
```