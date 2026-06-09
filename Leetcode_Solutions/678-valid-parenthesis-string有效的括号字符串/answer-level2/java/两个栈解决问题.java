1. 使用两个栈，一个保存左括号，一个保存星号
2. 在for循环s.length()的长度，遇见左括号存入left栈里，遇见星号存star栈里，否则最后遇到右括号就需要先判断left里是否有左括号匹配，如果为空在判断是否有星号匹配，如果都没有返回false；
3. for循环完判断left是否为空，不为空则需要星号来配对，直到left为空为止，如果星号为空，还有left栈，那就返回false了
```
class Solution {
    //思路，一个栈放左括号；一个栈放*号，在for循环里遇到右括号先判断退出左括号在判断*号有没
    //在for循环完后在判断两个栈的情况，如果左括号有，星号没有在输出false,都存在在判断，星号下标要大于左括号，最后都没问题在退出
    public boolean checkValidString(String s) {
        if(s.length()==0) {
            return true;
        }
        Stack<Integer> left = new Stack<>();
        Stack<Integer> star = new Stack<>();
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i)=='(') {
                left.push(i);
            }else if(s.charAt(i)=='*') {
                star.push(i);
            }else {
                if(!left.isEmpty()) {
                    left.pop();
                }else if(!star.isEmpty()) {
                    star.pop();
                }else {
                    return false;
                }
            }
        }
        while(!left.isEmpty()) {
            if(star.isEmpty()) {
                return false;
            }else if(left.peek()> star.peek()) {
                return false;
            }else {
                left.pop();
                star.pop();
            }
        }
        return true;
    }
}
```
