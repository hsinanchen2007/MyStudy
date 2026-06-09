

### 代码

```java
class Solution {
    public int calculate(String s) {
        if (s == null) {
            return 0;
        }

        int sign = 1;
        Deque<Integer> stack = new ArrayDeque<>();
        stack.addFirst(sign);
        int num = 0;
        int result = 0;

        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                result += sign * num;
                num = 0;
                sign = stack.getFirst() * (c == '+' ? 1 : -1);
            } else if (c == '(') {
                stack.addFirst(sign);
            } else if (c == ')') {
                stack.removeFirst();
            }
        }

        result += sign * num;
        return result;
    }
}
```