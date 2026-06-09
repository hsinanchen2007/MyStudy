### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    int index = 0;
    //s = "3[a2[c]]", 返回 "accaccacc".
    public String decodeString(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            StringBuilder sb = new StringBuilder();
            if (s.charAt(i) != ']') {
                stack.push(s.charAt(i));
                continue;
            }
            while (!stack.isEmpty() && stack.peek() != '[') {
                sb.insert(0, stack.pop());
            }
            //跳过'['
            stack.pop();

            int num = 0;
            int unit = 1;
            while (!stack.isEmpty() && Character.isDigit(stack.peek())) {
                num += (stack.pop() - '0') * unit;
                unit *= 10;
            }

            if(num == 0) {
                sb.delete(0, sb.length());
            } else {
                String sub = sb.toString();
                for (int j = 0; j < num - 1; j++) {
                    sb.insert(0, sub);
                }
            }

            String subRepeat = sb.toString();
            for (int j = 0; j < subRepeat.length(); j++) {
                stack.push(subRepeat.charAt(j));
            }

        }

        StringBuilder res = new StringBuilder();
        while (!stack.isEmpty()) {
            res.insert(0, stack.pop());
        }

        return res.toString();
    }
}
```