栈的应用
```
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack();
        for(String str : tokens){
            if(str.equals("+") || str.equals("-") || str.equals("*") || str.equals("/") ){
                int num1 = stack.pop();
                int num2 = stack.pop();
                if(str.equals("+"))  num2 += num1;
                if(str.equals("-"))  num2 -= num1;
                if(str.equals("*"))  num2 *= num1;
                if(str.equals("/"))  num2 /= num1;
                stack.push(num2);
               }else{
                stack.push(Integer.parseInt(str));
            }
        }
        
        return stack.pop();
    }
```
