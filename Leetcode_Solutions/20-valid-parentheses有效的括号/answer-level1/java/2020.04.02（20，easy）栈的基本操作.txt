### 解题思路
本题是栈学习的第一题，真切感受到栈的巧妙之处！

- 首先将所有类型的**左括号挨个入栈**，如果当前遍历元素不是左括号，要先判断栈中是否已经放入了左括号

- 如果栈的**长度为** `0` 则说明没有元素入栈，直接返回 `false` 即可

- 如果栈的**长度不为** `0` 就可以继续寻找与之对应的右括号

- 定义 `c` 来接收**非左括号**的栈顶元素，定义 `match` 来**匹配右括号**，期间若有不匹配的情况则返回 `false`

- 最后当右括号都匹配完了，如果栈中**还有剩余元素**，则说明左括号“溢出”，此时返回 `false`，否则返回 `true`

### 代码

```java []
class Solution {
    public boolean isValid(String s) {
        // 用栈来保存
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            // 如果遍历的是左括号，则入栈
            if (s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[') {
                stack.push(s.charAt(i) );
            } else {
                // 如果没有入栈元素即为空，就返回 false
                if (stack.size() == 0) {
                    return false;
                }
                // 接收栈顶元素
                Character c = stack.pop();
                // 定义 match 来接收与左括号相匹配的符号
                Character match;
                if ( s.charAt(i) == ')' ) {
                    match = '(';
                } else if ( s.charAt(i) == ']' ) {
                    match = '[';
                } else {
                    match = '{';
                }
                if (c != match) {
                    return false;
                }
            }            
        }
        // 匹配完了之后如果栈内还有剩余括号未进行匹配，则返回 false
        if (stack.size() != 0) {
            return false;
        }
        return true;
    }
}
```