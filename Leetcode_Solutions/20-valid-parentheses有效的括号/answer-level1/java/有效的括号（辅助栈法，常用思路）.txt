### 解题思路
利用栈的后进先出的特性，实现局部有效括号匹配

### 代码

```java
import java.util.Stack;
class Solution {
    public boolean isValid(String s) {    
        Stack<Character> stack = new Stack<>();
        char [] arr = s.toCharArray();
        for (int i =0; i < arr.length; i++) {
            //如果是开放括号就直接压栈
            if ( arr[i] == '(' || arr[i] == '[' || arr[i] == '{') {
                stack.push(arr[i]);
            }else{
                //特判
                if (stack.isEmpty()) {
                    return false;
                }
                //获取当前栈顶的元素
                char topChar = stack.peek();
                //判断是否为匹配的闭合括号，如果都不是，闭合括号压栈
                if (arr[i] == ')' && topChar == '(') {
                     stack.pop();
                } else if ( arr[i] == '}' && topChar == '{'){
                    stack.pop();
                } else if ( arr[i] == ']' && topChar == '['){
                    stack.pop();
                } else {
                    stack.push(arr[i]);
                }
            }
        }
    //如果栈为空，表示所有括号都匹配成功，返回true，否则返回false
    return stack.isEmpty();
    }
}
```