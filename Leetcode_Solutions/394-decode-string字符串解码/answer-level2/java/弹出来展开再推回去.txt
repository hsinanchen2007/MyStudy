### 解题思路
弹出来展开再推回去 注意实现细节

### 代码

```java
class Solution {
    public String decodeString(String s) {
        Stack<Character> stack = new Stack<>();
        char[] arr = s.toCharArray();
        StringBuilder sb = new StringBuilder();
        for (char c : arr) {
            if (c == ']') {
                String sub = "";
                while (stack.peek() != '[')
                    sub += stack.pop();
                // 弹出'['
                stack.pop();
                // 弹出数字
                StringBuilder multiStr = new StringBuilder();
                while (!stack.isEmpty() && stack.peek() >= '0' && stack.peek() <= '9')
                    multiStr.append(stack.pop());
                int multi = Integer.parseInt(multiStr.reverse().toString());
                for (int i = 0; i < multi; i++)
                    for (int j = sub.length() - 1; j >= 0; j--)
                        // 再把数字字符展开推入栈
                        stack.push(sub.charAt(j));
            } else
                stack.push(c);
        }
        while (!stack.isEmpty())
            sb.append(stack.pop());


        return sb.reverse().toString();
    }
}
```