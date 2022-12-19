```java
public int calPoints(String[] ops) {
        int score = 0;
        Stack<Integer> stack = new Stack<>();
        for (String op : ops) {
            switch (op) {
                case "D":
                    score += stack.push(stack.peek() * 2);
                    break;
                case "C":
                    score -= stack.pop();
                    break;
                case "+" :
                    score += stack.push(stack.elementAt(stack.size()-2) + stack.peek());
                    break;
                default:
                    score += stack.push(Integer.parseInt(op));
            }
        }
        return score;
    }
```
