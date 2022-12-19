### 解题思路
本题是个用栈的典型题目

- 首先定义栈来存放遍历到的**非运算符元素**

- 如果当前遍历到的是四大运算符，则将此时**前两个栈顶元素**做相应的运算，并将每次运算后的**结果压入栈**中

- 如果当前遍历到的不是运算符，则将该字符串**拆箱**成 `int` 后入栈

- 最后所有字符串经过相应运算后的结果就保留在栈中，此时将栈顶元素出栈即为最终所求结果。

### 代码

```java []
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (String s : tokens) {
            // 遍历每个字符串，如果遇到四种运算符就将栈顶前两个元素做对应的运算
            if (s.equals("+")) {
                // 将栈顶前两个元素做“+”运算后的结果再压入栈中
                stack.push(stack.pop() + stack.pop());
            } else if (s.equals("-")) {
                stack.push(-stack.pop() + stack.pop());
            } else if (s.equals("*")) {
                stack.push(stack.pop() * stack.pop());
            } else if (s.equals("/")) {
                int num1 = stack.pop();
                stack.push(stack.pop() / num1);
            } else {
                // 如果不是运算符，就将该字符串拆箱成 int 后入栈
                stack.push(Integer.parseInt(s));
            }
        }
        return stack.pop();
    }
}
```