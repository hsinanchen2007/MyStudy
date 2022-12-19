### 解题思路
224题基础上，+ - * / ( )都支持

### 代码

```java
class Solution {
    Stack<String> stack = new Stack<>();
    List<String> list = new LinkedList<>();

    public int calculate(String s) {
        // empty space
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != ' ') {
                sb.append(s.charAt(i));
            }
        }
        s = sb.toString();
        reversePolish(s);
        for (String s1 : list) {
            System.out.print(s1 + " ");
        }
        System.out.println("");
        return cal();

    }

    public void reversePolish(String s) {
        // 转换为逆波兰表达式
        for (int i = 0; i < s.length(); i++) {
            String c = String.valueOf(s.charAt(i));
            switch (c) {
                case "+":
                case "-":
                    while (!stack.isEmpty() && !stack.peek().equals("(")) {
                        list.add(stack.pop());
                    }
                    stack.push(c);
                    break;
                case "*":
                case "/":
                    while (!stack.isEmpty() && !sentry(stack.peek())) {
                        list.add(stack.pop());
                    }
                    stack.push(c);
                    break;
                case "(":
                    stack.push(c);
                    break;
                case ")":
                    while (!stack.peek().equals("(")) {
                        list.add(stack.pop());
                    }
                    stack.pop();
                    break;
                default:
                    String str = "";
                    while (i < s.length() && s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                        str += String.valueOf(s.charAt(i));
                        i++;
                    }
                    if (i != s.length()) {
                        i--;
                    }
                    list.add(str);
            }
        }
        while (!stack.isEmpty()) {
            list.add(stack.pop());
        }

    }

    public boolean sentry(String s) {
        if ("(".equals(s)) {
            return true;
        } else if ("*".equals(s) || "/".equals(s)) {
            return false;
        } else {
            return true;
        }
    }

    public int cal() {
        // 计算逆波兰表达式
        Stack<Integer> value = new Stack<>();
        for (String s : list) {
            switch (s) {
                case "+":
                    value.push(value.pop() + value.pop());
                    break;
                case "-":
                    Integer temp = value.pop();
                    value.push(value.pop() - temp);
                    break;
                case "*":
                    value.push(value.pop() * value.pop());
                    break;
                case "/":
                    Integer divide = value.pop();
                    value.push(value.pop() / divide);
                    break;
                default:
                    value.push(Integer.valueOf(s));
            }
        }
        return value.pop().intValue();
    }
}
```