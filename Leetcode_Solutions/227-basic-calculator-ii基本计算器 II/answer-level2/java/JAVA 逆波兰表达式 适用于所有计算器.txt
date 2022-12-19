```
class Solution {
    private Stack<Character> opStack = new Stack<>();
    private ArrayList<String> rpnList = new ArrayList<>();

    public int calculate(String s) {
        if (s == null || s.isEmpty()) {
            return 0;
        }
        char[] tokens = s.toCharArray();
        for (int i = 0; i < tokens.length; i++) {
            if (Character.isDigit(tokens[i])) {
                int num = tokens[i] - '0';
                for (int j = i + 1; j < tokens.length; j++) {
                    if (Character.isDigit(tokens[j])) {
                        num = num * 10 + tokens[j] - '0';
                    } else {
                        break;
                    }
                    i = j;
                }
                rpnList.add(String.valueOf(num));
            } else {
                switch (tokens[i]) {
                    case '+':
                    case '-':
                        getOp(tokens[i], 1);
                        break;
                    case '*':
                    case '/':
                        getOp(tokens[i], 2);
                        break;
                    case '(':
                        opStack.push(tokens[i]);
                        break;
                    case ')':
                        getPop();
                        break;
                }
            }
        }
        while (!opStack.isEmpty()) {
            rpnList.add(opStack.pop().toString());
        }
        //System.out.println(Arrays.deepToString(rpnList.toArray()));
        return evalRPN(rpnList.toArray(new String[0]));
    }

    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (String token : tokens) {
            switch (token) {
                case "+":
                    stack.push(stack.pop() + stack.pop());
                    break;
                case "-": {
                    Integer num = stack.pop();
                    stack.push(stack.pop() - num);
                    break;
                }
                case "*":
                    stack.push(stack.pop() * stack.pop());
                    break;
                case "/": {
                    Integer num = stack.pop();
                    stack.push(stack.pop() / num);
                    break;
                }
                default:
                    stack.push(Integer.parseInt(token));
                    break;
            }
        }
        return stack.pop();
    }

    public void getOp(Character op, int opOrder) {
        while (!opStack.isEmpty()) {
            Character topOp = opStack.peek();
            if (topOp == '(') {
                opStack.push(op);
                return;
            } else {
                int topOrder;
                if (topOp == '/' || topOp == '*') {
                    topOrder = 2;
                } else {
                    topOrder = 1;
                }
                if (opOrder > topOrder) {
                    opStack.push(op);
                    return;
                } else {
                    rpnList.add(opStack.pop().toString());
                }
            }
        }
        opStack.push(op);
    }
    public void getPop() {
        while (!opStack.isEmpty()) {
            Character top = opStack.pop();
            if (top == '(') {
                break;
            } else {
                rpnList.add(top.toString());
            }
        }
    }
}
```
