//使用栈存储结果数据，如果当前遍历的元素小于栈顶元素并且栈顶元素在后面的字符串中还存在则弹出，循环此情况。
```
 public  String smallestSubsequence(String text) {
        int len = text.length();
        char tmp;
        StringBuffer sb = new StringBuffer();
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < len; i++) {
            tmp = text.charAt(i);
            if (stack.contains(tmp))
                continue;
            while (!stack.isEmpty() && tmp < stack.peek() && text.lastIndexOf(stack.peek()) > i) {
                stack.pop();
            }
            stack.push(tmp);
        }
        while (!stack.isEmpty())
            sb.append(stack.pop());
        return sb.reverse().toString();
    }
```
