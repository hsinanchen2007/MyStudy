```java
class Solution {
    public String multiply(String num1, String num2) {
        if (num1.length() > num2.length()) {
            String tmp = num1;
            num1 = num2;
            num2 = tmp;
        }
        int len1 = num1.length();
        String ans = "0";
        for (int i = len1 - 1; i >= 0; i--) {
            int c = num1.charAt(i) - '0';
            if (i < len1 - 1) {
                num2 = num2.concat("0");
            }
            while (c-- > 0) {
                ans = addString(num2, ans);
            }
        }
        return ans;
    }

    private String addString(String num1, String num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        char[] ans = new char[len1 > len2 ? len1 + 1 : len2 + 1];
        int carry = 0;
        int i1 = len1 - 1;
        int i2 = len2 - 1;
        int i = ans.length - 1;
        while (i1 >= 0 || i2 >= 0) {
            int o1 = i1 >= 0 ? num1.charAt(i1--) - '0' : 0;
            int o2 = i2 >= 0 ? num2.charAt(i2--) - '0' : 0;
            int o = o1 + o2 + carry;
            carry = 0;
            if (o >= 10) {
                carry = 1;
                o -= 10;
            }
            ans[i--] = (char) (o + '0');
        }
        ans[i] = (char) (carry + '0');
        if (ans[0] == '0') {
            return String.valueOf(ans, 1, ans.length - 1);
        } else {
            return String.valueOf(ans);
        }
    }
}
```
