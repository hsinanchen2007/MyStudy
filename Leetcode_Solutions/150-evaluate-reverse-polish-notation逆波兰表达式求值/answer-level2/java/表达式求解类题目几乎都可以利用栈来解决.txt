```
class Solution {
    public int evalRPN(String[] tokens) {
        if(tokens == null || tokens.length < 1)
            return 0;
        Stack<Integer> stack = new Stack();
        for(String token : tokens){
            if(token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/")){
                int last = stack.pop();
                int pre = stack.pop();
                if(token.equals("+"))
                    stack.push(pre+last);
                else if(token.equals("-"))
                    stack.push(pre-last);
                else if(token.equals("*"))
                    stack.push(pre*last);
                else if(token.equals("/"))
                    stack.push(pre/last);
            }
            else
                stack.push(Integer.valueOf(token));
        }
        return stack.pop();
    }
}
```
