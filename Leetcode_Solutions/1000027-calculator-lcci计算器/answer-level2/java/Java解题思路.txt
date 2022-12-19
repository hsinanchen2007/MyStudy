### 解题思路
用栈解决，遇到加、减入栈，遇乘、除先计算再入栈；入栈完成后计算栈中元素和。

### 代码

```java
class Solution {
    public int calculate(String s) {
        Stack<Integer> stack = new Stack();
        char sign = '+';
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n; i++){
            char c = s.charAt(i);
            if (Character.isDigit(c)){
                num = num * 10 + (c - '0');
            }
            if (!Character.isDigit(c) && c != ' ' || i == n - 1){
                int pre;
                switch(sign){
                    
                    case '+': stack.push(num); break;
                    case '-': stack.push(-num); break;
                    case '*': 
                            pre = stack.pop();
                            stack.push(pre * num);
                            break;
                    case '/':
                            pre = stack.pop();
                            stack.push(pre / num);
                            break;
                }
                sign = c;
                num = 0;
            }
            
        }
        int res = 0;
        while(!stack.isEmpty()){
            res += stack.pop();
        }
        return res;
    }
}
```