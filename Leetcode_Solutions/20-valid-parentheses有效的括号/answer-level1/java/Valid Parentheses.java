### 解题思路
主要是栈匹配的问题，如果是左括号：(,{,[,则压栈，如果是右括号：),},],则将栈顶元素出栈，如果不匹配，则返回false，然后继续匹配下一个字符。循环结束，如果栈为空，则返回真，否则为假。

注意点：

- stack创建方法：`Stack<Character> stk = new Stack<>();`
- 出栈之前要检查栈是否为空：stk.empty()
- str.charAt(index):取得字符串下标为index的字符

### 代码

```java
class Solution {
    public boolean isValid(String s) {

        if(s == null || s.length() == 0){
            return true;
        }

        if(s.length()%2 == 1){
            return false;
        }

        Stack<Character> stk = new Stack<>();

        for(int i = 0; i < s.length(); i++){
            switch(s.charAt(i)){
                case '(':{
                    stk.push('(');
                    break;
                }
                case '[':{
                    stk.push('[');
                    break;
                }
                case '{':{
                    stk.push('{');
                    break;
                }   
                case ')':{
                    if(stk.empty() == false){
                        char c = stk.pop();

                        if(c != '(')
                            return false;
                    }

                    break;
                }
                case ']':{
                    if(stk.empty() == false){
                        char c = stk.pop();

                        if(c != '[')
                            return false;
                    }

                    break;
                }
                case '}':{
                    if(stk.empty() == false){
                        char c = stk.pop();

                        if(c != '{')
                            return false;
                    }

                    break;
                }                 
            }
        }

        if(stk.empty() == true)
            return true;
        else
            return false;
    }
}
```