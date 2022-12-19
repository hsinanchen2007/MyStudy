### 解题思路
将字符串 进行插空 ，  然后 分割，遍历所有字符串
将左括号 压入栈中， 按照就近原则 匹配右括号。 如果匹配成功，栈中弹出左括号； 如果匹配失败，
返回false ;
最后，如果 栈不为空 ，返回false 

### 代码
```java
class Solution {
    public boolean isValid(String s) {
        return operatorAnExpression(s);
    }
    // 括号匹配 ,输入的字符串 进行分割， 左括号 都押入栈中。然后 按照就近匹配原则，匹配
    public String  insertBlanks(String s){
            StringBuilder sB = new StringBuilder();
            for(char c: s.toCharArray()){
                if(c == '('||  c ==')'|| c=='{'|| c == '}'|| c=='['|| c== ']')
                    sB.append(" " +c +" ");
                else 
                    sB.append(c);
            }
            return sB.toString();
    }
    // 处理 字符串 
    public boolean  operatorAnExpression(String s){
            Stack<Character> stack = new Stack<>();

            s = insertBlanks(s);
            String[] tokens = s.split(" "); // 进行分割 

            // 遍历 ,然后 左括号 压入栈中 
            for(String token: tokens){
                    if(token.length() == 0)
                        continue;
                    else if(token.trim().charAt(0) == '(' || token.trim().charAt(0) =='{' || token.trim().charAt(0) =='[')
                        stack.push(token.charAt(0));

                    else if(token.charAt(0) ==')'){
                            if(stack.isEmpty())
                                return false;
                            else{
                                    if(stack.peek() =='(')
                                        stack.pop();
                                    else 
                                        return false;
                            }
                    }
                    else if(token.charAt(0) =='}'){
                            if(stack.isEmpty())
                                return false;
                            else{
                                    if(stack.peek()=='{')
                                            stack.pop();
                                    else 
                                        return false;
                            }
                    }
                    else if(token.charAt(0) ==']'){
                            if(stack.isEmpty())
                                return  false;
                            else{
                                    if(stack.peek() =='[')
                                        stack.pop();
                                    else 
                                        return false;
                            }
                    }
                    else 
                        continue;
            }
            // 判断栈 知否为空 
            return stack.isEmpty() ? true: false;
    }
}
```
