### 解题思路

### 代码

```java
class Solution {

      public  String decodeString(String s) {
        int num = 0,tempN;
        Stack<Integer> stackInt = new Stack<>();
        Stack<String> stackStr = new Stack<>();
        StringBuilder sb = new StringBuilder(), temp;
        for (char aChar : s.toCharArray()) {
            if (aChar == ']') {
                tempN = stackInt.pop();
                temp = new StringBuilder();
                while (tempN-- > 0) {
                    temp.append(sb);
                }
                sb = new StringBuilder(stackStr.pop() + temp);
            } else if (aChar >= '0' && aChar <= '9') {
                num = num * 10 + (aChar - '0');
            } else if (aChar == '[') {
                stackInt.push(num);
                num = 0;
                stackStr.push(sb.toString());
                sb = new StringBuilder();
            } else {
                sb.append(aChar);
            }
        }
        return sb.toString();
    }
}
```