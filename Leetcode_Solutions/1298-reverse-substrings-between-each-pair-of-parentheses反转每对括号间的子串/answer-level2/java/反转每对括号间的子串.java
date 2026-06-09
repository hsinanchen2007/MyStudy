### 解题思路
java

### 代码

```java
class Solution {
    public String reverseParentheses(String s) {
        Stack<Character> in = new Stack<>();
        Queue<Character> out = new LinkedList<>();
        for (char c : s.toCharArray()) {
            if (c == ')') {
                while(in.peek() != '(') out.add(in.pop());
                in.pop();
                while (!out.isEmpty()) in.push(out.poll());
            } else in.push(c);
        }
        StringBuilder sb = new StringBuilder();
        while (!in.isEmpty()) sb.append(in.pop());
        return sb.reverse().toString();
    }
}
```