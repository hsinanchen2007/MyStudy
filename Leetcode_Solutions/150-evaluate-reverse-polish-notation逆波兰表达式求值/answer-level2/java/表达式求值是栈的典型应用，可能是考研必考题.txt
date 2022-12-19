> 大部分数据结构教科书中，提到栈的应用时，基本上都会提到表达式求值。所以，如果教科书好好学习研究了，做这题真得是如同切菜！！


做这题如同切菜，得有以下几个前提：
1. 非常熟悉这个知识点：中缀表达式、后缀表达式（逆波兰式）
    这个知识点非常重要。在学数据结构的时候搞明白了，当在编译原理遇到这个知识点的时候，就可以一笔带过！
2. 对栈的特性理解非常到位：后进先出、先进后出
    这个特性，要烂熟于心。而且能做到不需要思维转换！
3. 深刻理解栈不仅可以作为一种”容器”，而且它是一种非常重要的辅助工具，辅助算法的实现！
    这一点非常非常非常重要。有第三点的认知，在遇到栈相关的算法题时，我们就能够如同切菜！我个人也是做了一些关于栈的算法题之后才总结出来这一点。
4. 如果一个栈解决不了，那就用两个！

以上四点点，如果暂时没有“感觉”，那就去做题，找到获取以上四点认知的感觉。

好了，有了以上四点，这一题具体的解题思路真没有什么好说的了，直接上代码吧：

```java
class Solution {
    public int evalRPN(String[] tokens) {
        Deque<Integer> stack = new ArrayDeque<>();
        for (String token : tokens) {
            if (isOperator(token)) {
                int operand01 = stack.pop();
                int operand02 = stack.pop();
                
                switch(token) {
                    case "+":
                        stack.push(operand02 + operand01);
                        break;
                    case "-":
                        stack.push(operand02 - operand01);
                        break;
                    case "*":
                        stack.push(operand02 * operand01);
                        break;
                    case "/":
                        stack.push(operand02 / operand01);
                        break;
                }
            } else {
                stack.push(Integer.parseInt(token));
            }
        }
        return stack.pop();
    }
    
    private boolean isOperator(String token) {
        if ("+".equals(token) 
            || "-".equals(token) 
            || "*".equals(token) 
            || "/".equals(token)) {
            return true;   
        }
        return false;
    }
}
```

**注意点：**
因为栈是后进先出，所以当获取两个操作数时，注意操作数在操作符的前后顺序，如果弄错了，可能导致零除异常和结果错误！