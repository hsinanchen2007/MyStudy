1. 栈的使用：
- 栈的定义：先进后出，后进先出。
- pop():弹出栈顶
- size():栈的长度
- peek():返回栈顶的数，但不删除
- empty():是否为空
```
public static boolean backspaceCompare(String S, String T) {
        Stack<Character> stack1 = new Stack<>();
        Stack<Character> stack2 = new Stack<>();
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == '#') {
                if (!stack1.empty()) {
                    stack1.pop();
                }

            } else {
                stack1.push(S.charAt(i));
            }

        }
        for (int j = 0; j < T.length(); j++) {
            if (T.charAt(j) == '#') {
                if (!stack2.empty())
                    stack2.pop();
            } else {
                stack2.push(T.charAt(j));
            }
        }
        if (stack1.size() != stack2.size()) {
            return false;
        }
        while (!stack1.empty()) { 
            if (stack1.pop() != stack2.pop()) {  // 一一判断是否相等
                return false;
            }
        }
        return true;
    }
```
