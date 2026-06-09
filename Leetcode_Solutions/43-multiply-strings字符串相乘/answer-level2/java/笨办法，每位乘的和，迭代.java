### 解题思路
笨办法，每位乘的和，迭代

### 代码

```java
class Solution {
     public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0"))
            return "0";
        //迭代
        String[] memo = new String[num2.length()];//num2前n位和num1的乘积
        int index = 0;
        for (int i = num2.length() - 1; i >= 0; i--) {
            if (num2.charAt(i) == '0') {
                memo[index] = index == 0 ? "0" : memo[index - 1];
                index++;
            } else {
                //乘法后进行加法
                //后缀0
                String suffix = "";
                for (int j = 0; j < num2.length() - i-1; j++)
                    suffix += "0";
                String str = multip(num1 + suffix, num2.charAt(i) - '0');
                memo[index] = plus(index==0 ? "0" : memo[index - 1], str);
                index++;
            }
        }

        return memo[memo.length - 1];
    }

    private String plus(String str1, String str2) {
        StringBuilder sb1 = new StringBuilder(str1).reverse();
        StringBuilder sb2 = new StringBuilder(str2).reverse();
        String longer = sb1.length() > sb2.length() ? sb1.toString() : sb2.toString();
        String shorter = sb1.length() > sb2.length() ? sb2.toString() : sb1.toString();
        StringBuilder res = new StringBuilder();
        int carry = 0;//进位
        for (int i = 0; i < longer.length(); i++) {
            int sum = longer.charAt(i) - '0' + (i >= shorter.length() ? 0 : (shorter.charAt(i) - '0')) + carry;
            res.append(sum % 10);
            carry = sum / 10;
            if (i == longer.length() - 1)
                res.append(carry == 0 ? "" : carry);

        }
        return res.reverse().toString();
    }

    private String multip(String str, int num) {
        if (num == 0)
            return "0";
        StringBuilder sb = new StringBuilder();
        int carry = 0;//进位
        for (int i = str.length() - 1; i >= 0; i--) {
            int mult = num * (str.charAt(i) - '0');
            if (i == 0) {
                int sum = mult + carry;
                sb.append(sum % 10);
                sb.append(sum / 10 == 0 ? "" : sum / 10);
            } else {
                sb.append((mult + carry) % 10);
                carry = (mult + carry) / 10;
            }
        }
        return sb.reverse().toString();
    }
}
```