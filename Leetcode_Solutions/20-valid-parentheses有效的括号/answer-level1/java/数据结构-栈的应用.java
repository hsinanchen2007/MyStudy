### 解题思路
此处撰写解题思路
定义一个栈，将所有的左括号压栈。
最后判断的时候需要注意：栈不为空时匹配也是失败的，栈不为空说明栈中还有未完成匹配的左括号。
### 代码

```java
import java.util.Stack;
public class Solution {
    public boolean isValid(String s){

        Stack<Character> stack = new Stack<>();
        for(int i = 0; i < s.length(); i ++){
            char c = s.charAt(i);
            if (c == '(' || c == '[' || c == '{')
                stack.push(c) ;
            else{
                if(stack.isEmpty())
                    return false;
                char topChar = stack.pop();
                if(c == ')' && topChar !='(')
                    return false;
                if(c == ']' && topChar != '[')
                    return false;
                if(c == '}' && topChar != '{')
                    return false;
            }
        }
        return stack.isEmpty();
    }
}

```