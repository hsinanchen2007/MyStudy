```
    private void trimString(String str, Stack<Character> stack) {
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) != '#') {
                stack.push(str.charAt(i));
            } else {
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            }
        }
    }

    public boolean backspaceCompare(String S, String T) {
        StringBuilder sb = new StringBuilder();
        Stack<Character> stack = new Stack<>();
        trimString(S, stack);
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        String tmpS = sb.toString();

        trimString(T, stack);
        if (stack.size() != tmpS.length()) {
            return false;
        }
        for (int i = 0; i < tmpS.length(); i++) {
            char c = stack.pop();
            if (tmpS.charAt(i) != c) {
                return false;
            }
        }
        return true;
    }
```

普遍做法是通过双栈保存字符串，再进行比较。
此处为了节省空间，栈内数据通过StringBuilder进行保存，这样栈就能实现重用。
