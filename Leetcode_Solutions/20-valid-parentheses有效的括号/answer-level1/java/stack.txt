### 解题思路
stack的特点是保留了最peek的元素
### 代码

```java
class Solution {
    public boolean isValid(String s) {
        Stack<Character> strStack=new Stack();
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            if(c==' '||c=='('||c==')'||c=='['||c==']'||c=='{'||c=='}'){
                if(!strStack.isEmpty()){
                    if(c==')'&&strStack.peek()=='('){
                        strStack.pop();
                    }
                    else if(c==']'&&strStack.peek()=='['){
                        strStack.pop();
                    }
                    else if(c=='}'&&strStack.peek()=='{'){
                        strStack.pop();
                    }
                    else if(c==' '&&strStack.peek()==' '){
                        strStack.pop();
                    }else{
                        strStack.push(c);
                    }
                }else{
                    strStack.push(c);
                }
            }else{
                return false;
            }
        }
        return strStack.empty();
    }
}
```