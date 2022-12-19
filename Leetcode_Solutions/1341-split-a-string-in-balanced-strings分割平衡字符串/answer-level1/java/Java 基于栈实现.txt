使用一个栈来实现该功能：
    1)当栈中没有元素时，当前字符入栈;
    2)当栈中有元素时，若栈顶字符与当前字符一致，字符入栈，否则栈顶出栈；
    3)检查当前栈是否为空，若为空则平衡次数+1；

对应代码如下：
```
public int balancedStringSplit(String s) {
    Stack<Character> stack = new Stack<Character>();
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        char c = s.charAt(i);
        if(stack.isEmpty() || c == stack.peek()) {
            stack.push(c);
        }
        else{
            stack.pop();
        }
        if(stack.isEmpty()) {
            count++;
        }
    }
    return count;
}
```
