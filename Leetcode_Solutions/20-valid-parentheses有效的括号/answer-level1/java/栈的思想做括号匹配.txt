### 解题思路


### 代码

```java
class Solution {
    public boolean isValid(String s) {
        //若字符串为空，则返回true
        if(s.isEmpty())
            return true;
        //若字符串长度为奇数，则返回false
        if(s.length()%2==1) return false;
        //创建栈
        Stack<Character> stack=new Stack<Character>();
        //遍历字符数组
        for(char c:s.toCharArray()){
            //若为左括号，将其对应的右括号压栈
            if(c=='(')
                stack.push(')');
            else if(c=='{')
                stack.push('}');
            else if(c=='[')
                stack.push(']');
            //若循环内栈为空或出栈的括号与遍历的括号不匹配，则返回false
            else if(stack.empty()||c!=stack.pop())
                return false;
        }
        //结束循环时栈为空，则返回true,否则返回false
        if(stack.empty())
            return true;
        return false;
    }
}
```