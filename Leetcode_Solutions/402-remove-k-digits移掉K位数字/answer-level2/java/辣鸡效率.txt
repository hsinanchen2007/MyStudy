### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String removeKdigits(String num, int k) {

        if (num.length() == k) {
            return "0";
        }
        while (k-- > 0) {
            int i = 1;
            while (i < num.length() && num.charAt(i-1) <= num.charAt(i)) {
                ++i;
            }
            num = num.replaceFirst(String.valueOf(num.charAt(i-1)), "");
        }
         int i = 0;
        while (i < num.length()) {
            if (num.charAt(i) != '0') {
               break;
            }
            ++i;
        }
        StringBuilder sb = new StringBuilder(num.substring(i));
        return sb.toString().length() == 0 ? "0" : sb.toString();
    }
}
```