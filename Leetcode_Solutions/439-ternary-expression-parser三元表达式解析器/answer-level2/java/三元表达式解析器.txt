### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String parseTernary(String expression) {
        //由于从后向前遍历，因此我们采用栈这种数据结构
        Stack<Character> stack=new Stack<>();
        for(int i=expression.length()-1;i>=0;i--)
        {
            char c=expression.charAt(i);
            if(!stack.isEmpty()&&stack.peek()=='?')
            {
                stack.pop();
                char First=stack.pop();
                stack.pop();
                char Second=stack.pop();
                if(c=='T')
                    stack.push(First);
                else
                    stack.push(Second);
            }
            else
                stack.push(c);
        }
        return String.valueOf(stack.peek());
    }
}
```