### 解题思路
遍历数组
如果为数字则推入栈中
如果是运算符则取栈顶两个数字进行运算
运算之后把结果推入栈 
进行下一步计算

### 代码

```java
class Solution {
    public int evalRPN(String[] tokens) {
        int res = 0;
        Stack<Integer> stack = new Stack<>();
        for (String token : tokens){
            //如果是数字 则推入栈中
            if ((!token.equals("+")) && (!token.equals("-")) && (!token.equals("*")) &&
                    (!token.equals("/"))){
                stack.push(Integer.valueOf(token));
            }else {
                //运算符则从栈顶取出两个数字进行计算
                int after = stack.pop();
                int before = stack.pop();

                switch (token){
                    case "+" :
                        res = before + after;
                        break;

                    case "-" :
                        res = before - after;
                        break;

                    case "*" :
                        res = before * after;
                        break;

                    case "/" :
                        res = before / after;
                        break;
                }
                //运算后把结果推入栈顶 进行后面的计算
                stack.push(res);
            }
        }
        //栈顶值即为结果
        return stack.pop();
    }
}
```