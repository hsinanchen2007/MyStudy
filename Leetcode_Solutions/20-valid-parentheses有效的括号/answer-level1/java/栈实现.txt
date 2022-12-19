```
代码块    public boolean isValid(String s) {
        if (s.length() == 0) {
            return true;
        }
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[') {
                stack.add(s.charAt(i));
            } else {
                if (s.charAt(i) == ')' && !stack.isEmpty() && stack.peek() == '(') {
                    stack.pop();
                } else if (s.charAt(i) == '}' && !stack.isEmpty() && stack.peek() == '{') {
                    stack.pop();
                } else if (s.charAt(i) == ']' && !stack.isEmpty() && stack.peek() == '[') {
                    stack.pop();
                } else {
                    stack.add(s.charAt(i));
                }
            }
        }
        return stack.size() == 0;
    }
```
