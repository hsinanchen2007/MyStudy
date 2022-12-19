将括号转换为数字，可以统一匹配条件，减少思考量，分分钟过关

```
import java.util.ArrayList;
import java.util.Stack;

/**
 * https://leetcode-cn.com/problems/valid-parentheses/
 * 包含[](){}的有效括号判断
 * 使用014589表示()[]{}六种括号，奇数入栈，偶数出栈，相差为1的符合条件
 */

public class Solution {
    public boolean isValid(String s) {
        ArrayList<Integer> arrayList = new ArrayList<>();
        for (Character c : s.toCharArray()) {
            arrayList.add(convertParentheseToInt(c));
        }

        Stack<Integer> stack = new Stack<>();

        for (Integer i : arrayList) {
            if (i % 2 == 0) {
                stack.push(i);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }
                if (i - stack.pop() != 1) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

    int convertParentheseToInt(Character c) {
        switch (String.valueOf(c)) {
            case "(":
                return 0;
            case ")":
                return 1;
            case "[":
                return 4;
            case "]":
                return 5;
            case "{":
                return 8;
            case "}":
                return 9;
            default:
        }
        return -1;
    }

}

```
