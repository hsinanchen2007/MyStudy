
```java []

class Solution {
    //有效的括号
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        char[] str = s.toCharArray();
        for(char i :str)
        {
            //如果是空栈直接进栈
            //如果不匹配也进栈
            if(stack.isEmpty()||!isCompare(stack.peek(),i))
            {
                stack.push(i);
            }
            //匹配出栈
            else if(isCompare(stack.peek(),i)){
                stack.pop();
            }
        }
        return stack.isEmpty();
    }
    //匹配函数
    private boolean isCompare(char a , char b){
        if (a == '{' && b=='}') {
            return true;
        }else if(a=='('&&b==')'){
            return true;
        }else return a == '[' && b == ']';
    }
    
}
```
