开始一遍遍历字符串，用栈保存左括号的下标,当遇到右括号而且栈非空时,栈顶元素出栈;当遇到右括号而且栈为空时,将右括号的下标
保存到需要删除的数组中;这个时候栈里面的下标和数组中的下标都是需要删除的元素下标，于是将栈中的下标加入数组中;最后
遍历字符串,当下标不在不要删除的数组中时才是我们需要的.
代码如下:
```
public String minRemoveToMakeValid(String s) {

        if (s == null || s.length() == 0) {
            return s;
        }

        int n = s.length();
        Stack<Integer> stack = new Stack<>();
        int[] removeArr = new int[n];
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == '(') {
                stack.push(i);
            } else if (c == ')') {
                if (!stack.isEmpty()) {
                    stack.pop();
                } else {
                    removeArr[i] = 1;
                }
            }
        }

        while (!stack.isEmpty()) {
            removeArr[stack.pop()] = 1;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (removeArr[i] == 0) {
                sb.append(s.charAt(i));
            }
        }

        return sb.toString();
    }
```
