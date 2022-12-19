![image.png](https://pic.leetcode-cn.com/2fafee650025d8730d23d58b4928e2d26bcc2f345fe01d7cce9c34ab4680e383-image.png)

直接遍历字符串，先拿到栈顶元素，如果栈为空，就先将元素压入栈内，不为空的话，就先和字符串的元素进行比较，如果相等就出栈，否则就压入栈内，重复这个步骤，最后即可。
```
Stack<Character> stack = new Stack<>();
        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            if (stack.empty()) {
                stack.push(c);
            } else {
                char topChar = stack.peek();
                if (topChar == c){
                    stack.pop();
                } else {
                    stack.push(c);
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (Character character : stack) {
            sb.append(character);
        }
        return sb.toString();
```

