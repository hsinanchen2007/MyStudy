### 解题思路
也可以自己用栈实现。

### 代码

```java
class Solution {
    int index = 0;
    //s = "3[a2[c]]", 返回 "accaccacc".
    public String decodeString(String s) {
        StringBuilder sb = new StringBuilder();
        int num = 0;

        while(index < s.length()) {
            if(Character.isDigit(s.charAt(index))) {
                num = num * 10 + s.charAt(index) - '0';
                index++;
            } else if (s.charAt(index) == '[') {
                index++;
                System.out.println(num);
                String sub = decodeString(s);
                for (int i = 0; i < num; i++) {
                    sb.append(sub);
                }
                num = 0;
            } else if (s.charAt(index) == ']') {
                index++;
                return sb.toString();
            } else {
                sb.append(s.charAt(index));
                index++;
            }
        }

        return sb.toString();
    }
}
```