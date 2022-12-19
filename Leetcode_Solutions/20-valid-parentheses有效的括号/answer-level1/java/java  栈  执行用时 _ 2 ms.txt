### 解题思路
从头遍历字符串，左括号则入栈，右括号则出栈一个检查是否为一对括号，不是的话返回false。尤其注意字符串为空、只有左括号和只有右括号的特殊情况。

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        int n = s.length();
        if (n == 0) return true;  //字符串为空

        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < n; i ++) {
            if (s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[')
                stack.push(s.charAt(i));
            else {
                if (!stack.isEmpty()){  //若栈空则表明只有右括号，返回false
                    char temp = stack.pop();
                    if (!isTwins(temp,s.charAt(i)))
                        return false;
                }else {
                    return false;
                }
            }
        }

        if (stack.size() == 0)  //检查是否有只有左括号的情况
            return true;
        else 
            return false;
    }

    public boolean isTwins(char a, char b){
        if (b == ')'){
            if (a == '(')
                return true;
        }
        else if (b == '}'){
            if (a == '{')
                return true;
        }
        else {
            if (a == '[')
                return true;
        }
        
        return false;
    }
}
```