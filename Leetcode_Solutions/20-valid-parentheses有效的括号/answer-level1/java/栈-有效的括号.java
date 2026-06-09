### 解题思路

1.迭代字符串，顺序获取取字。
2.当前字符为左括号，则保存到栈中，当前字符为右括号，则判断与栈顶符号是否匹配，不匹配，则return false，匹配则pop栈顶元素。
3.判断是否为空栈，是则return true，否则return false。

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        Map<String,Integer> nums = new HashMap<String,Integer>();
        nums.put("(",0);
        nums.put(")",1);
        nums.put("{",2);
        nums.put("}",3);
        nums.put("[",4);
        nums.put("]",5);
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('||s.charAt(i)=='['||s.charAt(i)=='{'){
                stack.push(s.charAt(i));
            }
            else{
                if(stack.empty()){
                    return false;
                }
                if(s.charAt(i)==')'){
                    if(stack.peek()!='('){
                        return false;
                    }
                    else{
                        stack.pop();
                    }
                }
                if(s.charAt(i)=='}'){
                    if(stack.peek()!='{'){
                        return false;
                    }
                    else{
                        stack.pop();
                    }
                }
                if(s.charAt(i)==']'){
                    if(stack.peek()!='['){
                        return false;
                    }
                    else{
                        stack.pop();
                    }
                }
            }
        }
        if(stack.empty()){
                return true;
            }
            else{
                return false;
            }
    }
}
```