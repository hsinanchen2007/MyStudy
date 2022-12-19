
### 代码

```java
class Solution {
    public boolean isValid(String s) {
        int len = s.length();
        Stack<Character> stack = new Stack<>();
        for(int i = 0;i<len;i++){
            char c = s.charAt(i);
            if(c == '(' || c== '[' || c == '{')
            stack.push(c);
            else{
                if(stack.isEmpty()) return false;
                char left = stack.pop();
                if(left == '(' && c != ')') return false;
                if(left == '[' && c != ']') return false;
                if(left == '{' && c != '}') return false;
            }
        }
        return stack.isEmpty();
    }
}
```