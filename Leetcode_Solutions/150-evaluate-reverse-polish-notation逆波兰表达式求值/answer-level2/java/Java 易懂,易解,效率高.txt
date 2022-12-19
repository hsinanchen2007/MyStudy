**1.逆波兰表达式求解,定义一个栈辅助计算;
2.当遇到运算符"+"、"-"、"*"、"/"时,从栈中pop出两个数字计算,否则将数字入栈;
3.完结。**

        public int evalRPN(String[] tokens) {
            Stack<Integer> stack = new Stack<>();
            for (String s : tokens) {
                if (s.equals("+")) {
                    stack.push(stack.pop() + stack.pop());
                } else if (s.equals("-")) {
                    stack.push(-stack.pop() + stack.pop());
                } else if (s.equals("*")) {
                    stack.push(stack.pop() * stack.pop());
                } else if (s.equals("/")) {
                    int num1 = stack.pop();
                    stack.push(stack.pop() / num1);
                } else {
                    stack.push(Integer.parseInt(s));
                }
            }
            return stack.pop();
        }