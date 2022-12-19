### 解题思路


### 代码

```java
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for(String s : tokens)
        {
            if(isNumeric(s))
            {
                stack.push(Integer.parseInt(s));
            }
            else 
            {
                int num2 = stack.pop();
                int num1 = stack.pop();
                if(s.equals("+"))
                  stack.push(num1+num2);
                if(s.equals("-"))
                  stack.push(num1-num2);
                if(s.equals("*"))
                  stack.push(num1*num2);
                if(s.equals("/"))
                  stack.push(num1/num2);
            }
        }
        return stack.pop();
    }
    public static boolean isNumeric(String str){
        if(str.charAt(0)=='-'&&str.length()>1)
        return true;
        for (int i = 0; i < str.length(); i++)
        if(!Character.isDigit(str.charAt(i)))
        return false;
        return true;
   }
}
```