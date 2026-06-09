```
public static String removeDuplicates(String s, int k) {
        Stack<Character> stack = new Stack<>();
        int[] num = new int[s.length()];
        StringBuilder stringBuilder = new StringBuilder();
        for (int index = 0; index < s.length(); index++) {
            Character cha = s.charAt(index);
            if (stack.isEmpty()) {
                stack.push(cha);
                num[0] = 1;
                continue;
            }
            if (stack.peek() != cha) {
                stack.push(cha);
                num[stack.size() -1] = 1;
            } else {
                num[stack.size() -1] += 1;
            }
            if (num[stack.size() -1] == k) {
                stack.pop();
            }
        }
        while (!stack.isEmpty()) {
            Character character = stack.pop();
            for (int i = 0; i < num[stack.size()]; i++) {
                stringBuilder.append(character);
            }
        }
        return stringBuilder.reverse().toString();
    }
```
