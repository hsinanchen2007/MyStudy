### 解题思路
执行用时 :4 ms, 在所有 Java 提交中击败了27.78%的用户
内存消耗 :35.9 MB, 在所有 Java 提交中击败了76.97%的用户
我是不是没救了！！！

### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
        StringBuilder res = new StringBuilder();
        int carry = 0;
        int additionBit = 0;
        int aLen = a.length() - 1;
        int bLen = b.length() - 1;
        int x, y;
        while (aLen >= 0 || bLen >= 0) {
            if (aLen < 0){
                x = 0;
            } else {
                x = Integer.valueOf(String.valueOf(a.charAt(aLen)));
            }
            if (bLen < 0){
                y = 0;
            } else {
                y = Integer.valueOf(String.valueOf(b.charAt(bLen)));
            }
            additionBit = (x ^ y) ^ carry;
            carry = (x + y + carry >= 2) ? 1 : 0;
            res.append(additionBit);
            aLen--;
            bLen--;
        }
        res.append(carry == 1 ? 1 : "");
        return res.reverse().toString();
    }
}
```