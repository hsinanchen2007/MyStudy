首先采用二进制加法的计算方式，得到一个整形的包含相加结果的数组，再将数组转化为字符串返回。
```java []
class Solution {
    public String addBinary(String a, String b) {
        int length = Math.max(a.length(), b.length());
        while (a.length() < length) {
            a  = '0' + a;
        }
        while (b.length() < length) {
            b = '0' + b;
        }
        int carry = 0;
        int[] result = new int[length];
        for (int i = length - 1; i >= 0; i --) {
            int sum = a.charAt(i) - '0' + b.charAt(i) - '0';
            if (carry > 0) {
                sum += carry;
                carry = 0;
            }
            if (sum >= 2) {
                carry = 1;
            }
            result[i] = sum % 2;
        }
        StringBuffer res = new StringBuffer();
        for (int i = 0; i < length; i ++) {
            res.append(result[i]);
        }
        if (carry > 0) {
            res.insert(0, '1');
        }
        return res.toString();
    }
}
```
