
```java
    /*
     * 执行用时 : 10 ms, 在Evaluate Reverse Polish Notation的Java提交中击败了89.68%
     * 的用户
     * 内存消耗 : 36.7 MB, 在Evaluate Reverse Polish Notation的Java提交中击败了90.36%
     *  的用户
     * 刚开始建的是Stack<String>, beat 12.24%，换Stack<Integer>效率就上来了
     */
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<Integer>();
        for (String token : tokens) {
            if (!token.equals("+")
                    && !token.equals("-")
                    && !token.equals("*")
                    && !token.equals("/")) {
                stack.push(Integer.parseInt(token));
            } else {
                int e2 = stack.pop();
                int e1 = stack.pop();
                stack.push(calculate(e1, e2, token));
            }
        }
        return stack.pop();
    }

    private int calculate(int i1, int i2, String op) {
        Integer res = new Integer(0);
        switch (op) {
            case "+":
                res = i1 + i2;
                break;
            case "-":
                res = i1 - i2;
                break;
            case "*":
                res = i1 * i2;
                break;
            case "/":
                if (i2 != 0) {
                    res = i1 / i2;
                }
                break;
        }
        return res;
    }
```
