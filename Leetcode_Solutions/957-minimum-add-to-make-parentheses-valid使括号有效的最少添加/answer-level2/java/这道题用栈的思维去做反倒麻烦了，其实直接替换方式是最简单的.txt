```
Stack<Integer> stack = new Stack<>();
        int result = 0;
        for (int index = 0; index < S.length(); index++) {
            Character character = S.charAt(index);
            if ('(' == character) {
                stack.push(index);
            } else {
                if (!stack.isEmpty()) {
                    stack.pop();
                } else {
                    result++;
                }
            }
        }
        return result + stack.size();
```
