### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        if(s.length()%2==1){return false;}
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if (stack.empty()){
                stack.push(s.charAt(i));
            }else{
                Character peek = stack.peek();
                if(peek.equals('(')){
                    if (s.charAt(i)==')') {
                        stack.pop();
                    }else {
                        stack.push(s.charAt(i));
                    }
                }else if(peek.equals('[')){
                    if (s.charAt(i)==']') {
                        stack.pop();
                    }else {
                        stack.push(s.charAt(i));
                    }
                }else if(peek.equals('{')){
                    if (s.charAt(i)=='}') {
                        stack.pop();
                    }else {
                        stack.push(s.charAt(i));
                    }
                }else{
                    stack.push(s.charAt(i));
                }
            }
        }
        if (stack.empty()){
            return true;
        }
        return false;
    }
}
```