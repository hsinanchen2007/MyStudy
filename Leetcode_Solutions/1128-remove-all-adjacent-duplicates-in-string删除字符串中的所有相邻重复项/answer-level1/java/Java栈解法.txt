每次进栈前判断栈顶是否与将要进栈的元素相同，是则出栈，否则进栈。直至全部元素处理完成。
```
class Solution {
    public String removeDuplicates(String S) {
        Stack<Character> stack = new Stack();
        int length = S.length();
        for (int i = 0; i < length; i++) {
            if (!stack.isEmpty()) {
                if (stack.peek() == S.charAt(i)) {
                    stack.pop();
                    continue;
                }
            }
            stack.push(S.charAt(i));
        }
        StringBuilder result = new StringBuilder();
        stack.forEach(character -> result.append(character));
        return result.toString();
    }
}
```
