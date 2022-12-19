### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String removeOuterParentheses(String S) {
        StringBuilder sb=new StringBuilder();
        Stack<Character> stack=new Stack<>();
        for(int i=0;i<S.length();i++)
        {
            char tmp=S.charAt(i);
            if(tmp==')')
                stack.pop();
            if(!stack.isEmpty())  //只要栈不空（不是最外层）
                sb.append(tmp);
            if(tmp=='(')
                stack.push(tmp);
        }
        return sb.toString();
    }
}
```