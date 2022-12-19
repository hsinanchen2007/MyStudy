当遇到‘(’时就入栈相应的下标遇到‘)’就出栈 要保证栈中永远有一下标(实为下一个有效括号的前一个下标) .

可能叙述的不是很清楚， 第一次发布题解


```
class Solution {
    public int longestValidParentheses(String s) {
        int max = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '('){
                stack.push(i);
            }else {
                stack.pop();
                if (stack.empty()){//记录 下一个有效括号的前一个下标
                    stack.push(i);
                }else {
                    max = Math.max(max,i - stack.peek());
                }
            }
        }
        return max;
    }
}
```

