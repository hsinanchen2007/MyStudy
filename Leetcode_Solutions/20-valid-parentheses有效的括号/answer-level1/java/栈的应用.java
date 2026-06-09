### 解题思路

观察合法的字符串，会发现，最里面的的一对括号，必然时一对，切中间没有任何字符。

遍历字符数组，使用栈数据结构，不断push，当到达最里面的一对括号后，pop该对括号，然后一层一层pop，最终如果栈被清空了，说明是合法字符串。

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        final char[] chars = s.replaceAll(" ", "").toCharArray();
        Stack<Character> stack = new Stack<>();
        
        for (char aChar : chars) {
            
             if(stack.isEmpty()){
                    stack.push(aChar);
                    continue;
                } 
            
            if((stack.peek()=='{' && aChar=='}') ||  (stack.peek()=='(' && aChar==')') ||  (stack.peek()=='[' && aChar==']')){
                stack.pop();
            }else{
                stack.push(aChar);
            }
        }
        return stack.isEmpty();
    }
}
```