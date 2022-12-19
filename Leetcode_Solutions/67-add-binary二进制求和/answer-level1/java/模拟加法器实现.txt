### 解题思路
    我们从两字符串的末尾开始，对于每一位依次进行二进制运算；
    由于每一位都可以保证是0001或0000，因此只要模拟加法器实现方式，就可以获取当前位的结果和下一个         carry；

### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        StringBuilder sb = new StringBuilder();
        while (i >= 0 || j >= 0) {
            int v1 = i >= 0 ? a.charAt(i) - '0' : 0;
            int v2 = j >= 0 ? b.charAt(j) - '0' : 0;
            int temp = (v1 ^ v2) ^ carry;
            carry = (v1 & v2) | (v1 & carry) | (v2 & carry);
            sb.append(temp);
            i--; j--;
        }
        if (carry > 0) {
            sb.append(carry);
        }
        return sb.reverse().toString();
    }
}
```