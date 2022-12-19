### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String addStrings(String num1, String num2) {
        String revers1 = new StringBuffer(num1).reverse().toString();
        String revers2 = new StringBuffer(num2).reverse().toString();

        int carry = 0;
        StringBuffer result = new StringBuffer();
        while (!revers1.equals("") && !revers2.equals("")) {
            int value = Integer.parseInt(revers1.substring(0, 1)) + Integer.parseInt(revers2.substring(0, 1)) + carry;
            carry = value / 10;
            value = value % 10;
            result.append(value);
            revers1 = revers1.substring(1);
            revers2 = revers2.substring(1);
        }
        while (!revers1.equals("")) {
            int value = Integer.parseInt(revers1.substring(0, 1)) + carry;
            carry = value / 10;
            value = value % 10;
            result.append(value);
            revers1 = revers1.substring(1);
        }

        while (!revers2.equals("")) {
            int value = Integer.parseInt(revers2.substring(0, 1)) + carry;
            carry = value / 10;
            value = value % 10;
            result.append(value);
            revers2 = revers2.substring(1);
        }
        if (carry == 1) {
            result.append(1);
        }
        return new StringBuffer(result).reverse().toString();
    }
}
```