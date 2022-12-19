```
public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        char[] chars = s.toCharArray();
        for (char c : chars) {
            if (stack.size() != 0) {
                if ((c == ')' && stack.peek() == '(') || (c == ']' && stack.peek() == '[') || (c == '}' && stack.peek() == '{')) {
                    stack.pop();
                    continue;
                }
            }
            stack.push(c);
        }
        return stack.size() == 0;
    }
```

![捕获.JPG](https://pic.leetcode-cn.com/2375ec38fe4b5bf8ece6f043ebdcf28c8910be5d329a386ec3d197c444428846-%E6%8D%95%E8%8E%B7.JPG)
