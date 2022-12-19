```
    private static boolean isDigital(String string) {
        for (int i = 0; i < string.length(); i++) {
            if (!Character.isDigit(string.charAt(i))) {
                return false;
            }
        }
        return true;
    }
    public static int calculate(String s) {
        Stack<String> stackBefore = new Stack<String>();
        ArrayList<String> output = new ArrayList<String>();
        Stack<Integer> stackAfter = new Stack<Integer>();
        s = s.replace("(", " ( ").replace(")", " ) ").replace("+", " + ").replace("-", " - ");
        String[] strings = s.split(" ");
        for (int i = 0; i < strings.length; i++) {
            String string = strings[i];
            string = string.trim();
            if (string.isEmpty()) {
                continue;
            } else if (isDigital(string)) {
                output.add(string);
            } else if (string.equals(")")) {
                while (!stackBefore.peek().equals("(")) {
                    output.add(stackBefore.pop());
                }
                stackBefore.pop();
            } else {
                if (!stackBefore.isEmpty() && (string.equals("+") || string.equals("-"))) {
                    if (stackBefore.peek().equals("+") || stackBefore.peek().equals("-")) {
                        output.add(stackBefore.pop());
                    }
                }
                stackBefore.add(string);
            }
        }
        while (!stackBefore.isEmpty()) {
            output.add(stackBefore.pop());
        }
        for (int i = 0; i < output.size(); i++) {
            String string = output.get(i);
            if (isDigital(string)) {
                stackAfter.add(Integer.valueOf(string));
            } else {
                int num2 = stackAfter.pop();
                int num1 = stackAfter.pop();
                if (string.contentEquals("+")) {                    
                    stackAfter.add(num1 + num2);
                } else {
                    stackAfter.add(num1 - num2);
                }
            }
        }
        return stackAfter.pop();
    }
```
