### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.Stack;
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack=new Stack<>();
        for (int i = 0; i <s.length() ; i++) {
            char c=s.charAt(i);
            if(c=='('||c=='['||c=='{'){
                stack.push(c);
            }
            else{
                if (stack.isEmpty()){
                    return false;
                }
                char  topchar =stack.pop();
                if (c==')'&&topchar!='('){
                    return false;
                }
                if (c==']'&&topchar!='['){
                    return false;
                }
                if (c=='}'&&topchar!='{'){
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
}
```