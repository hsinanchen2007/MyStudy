
### 代码

```java
class Solution {
    public boolean parseBoolExpr(String expression) {
        // base case: t/f
        if (expression.length() == 1) {
            return expression.equals("t");
        }
        // first character must be ！ | &
        char opt = expression.charAt(0);
        int pre = 2; // 子问题开始位置
        int count = 0;
        for (int i = 2; i < expression.length(); i++) {
            if (expression.charAt(i) == '(') {
                count++;
            } else if (i != expression.length() - 1 && expression.charAt(i) == ')') {
                count--;
            }
            if (count == 0 && (expression.charAt(i) == ',' || i == expression.length() - 1)) {      
                // 左右括号匹配，为逗号，或者是最后，找到一个子问题结束位置
                boolean sub = parseBoolExpr(expression.substring(pre, i));
                // 处理不同运算符
                if (opt == '!') {
                    return !sub;
                }
                if (opt == '|' && sub) {
                    return true;
                }

                if (opt == '&' && !sub) {
                    return false;
                }
                pre = i + 1;
            }
        }
        return opt == '&';
    }
}
```


附上stack的写法 13ms
### 代码

```java
class Solution {
    public boolean parseBoolExpr(String expression) {
        Deque<Character> stack = new ArrayDeque<>();
        for (int i = 0; i < expression.length(); i++) {
            char cur = expression.charAt(i);
            if (cur == ')') {
                List<Character> list = new ArrayList<>();
                while (stack.peek() != '(') {
                    list.add(stack.pop());
                }
                stack.pop();
                stack.push(compute(stack.pop(), list) ? 't' : 'f');
            } else if (cur == ','){
                continue;
            }else {
                stack.push(cur);
            }
        }
        return stack.peek() == 't';
    }

    private boolean compute(char opt, List<Character> list) {
        if (opt == '!') {
            return list.get(0) == 'f';
        } else if (opt == '|') {
            for (char b : list) {
                if (b == 't') {
                    return true;
                }
            }
            return false;
        }

        for (char b : list) {
        if (b == 'f') {
            return false;
            }
        }
        return true;
    }
}
```