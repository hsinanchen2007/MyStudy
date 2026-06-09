### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        if ("".equals(s)) return true;
        char[] str = new char[s.length()];
        //模拟栈顶指针
        int top = -1;
        for (int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if (isLeft(c)){
                str[++top] = c;
            }
            if (isRight(c)){
                if (top == -1){
                    return false;
                }else {
                    if (matches(str[top],c)){
                        top--;
                    }else {
                        return false;
                    }
                }
            }
        }
        return top == -1;
    }
    private boolean matches(char left,char right){
        if ('(' == left && right == ')') return true;
        if ('[' == left && right == ']') return true;
        if ('{' == left && right == '}') return true;
        return false;
    }
    private boolean isLeft(char c){
        return c == '(' || c == '[' || c == '{';
    }
    private boolean isRight(char c){
        return c == ')' || c == ']' || c == '}';
    }
}
```