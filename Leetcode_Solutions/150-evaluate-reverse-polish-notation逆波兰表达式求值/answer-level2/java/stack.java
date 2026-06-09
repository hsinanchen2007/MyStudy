class Solution {
    //运算规则为：运算符在式中出现的顺序恰为表达式的运算顺序；
    //每个运算符和在它之前出现且紧靠它的两个操作数构成一个最小表达式
    //逆波兰表达式的输入最后加一个 # 表示输入的结束。建立一个存放 double 型数字的栈，
    //用一个数组存放需要输入的操作数的每个字符（包括小数点），操作符和运算符之间用空格隔开
    
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for(String s: tokens){
            switch(s){
                case "+":
                    
                    stack.push(stack.pop() + stack.pop());
                    break;
                case "-":
                    Integer second = stack.pop();
                    Integer first = stack.pop();
                    stack.push(first - second);
                    break;
                case "*":
                    stack.push(stack.pop() * stack.pop());
                    break;
                case "/":
                    // 0 8 stack.pop()/stack.pop()--> 8/0
                    Integer second1 = stack.pop();
                    Integer first1 = stack.pop();
                    stack.push(first1/second1);
                    break;   
                default:
                    stack.push(Integer.valueOf(s));
                    break;
            }
        }
        return stack.pop();
    }
}