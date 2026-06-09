    public int evalRPN(String[] tokens) {
        int result = 0;
        if (tokens.length == 0) {
            return 0;
        }
        if (tokens.length == 1) {
            return Integer.valueOf(tokens[0]);
        }
        Stack<String> stack = new Stack();
        for (int i = 0; i < tokens.length; i++) {
            if (!tokens[i].equals("+") && !tokens[i].equals("-") && !tokens[i].equals("*") && !tokens[i].equals("/")) {
                stack.push(tokens[i]);
            } else if (!stack.empty()) {
                int b = Integer.valueOf(stack.pop());
                int a = Integer.valueOf(stack.pop());
                if (tokens[i].equals("+")) {
                    result = a + b;
                } else if (tokens[i].equals("-")) {
                    result = a - b;
                } else if (tokens[i].equals("*")) {
                    result = a * b;
                } else {
                    result = a / b;
                }
                stack.push(String.valueOf(result));
            }
        }
        return result;
    }