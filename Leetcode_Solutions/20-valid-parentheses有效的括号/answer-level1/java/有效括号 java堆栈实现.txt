```java
class Solution {
   public boolean isValid(String s) {
        Map<Character, Character> map = new HashMap<Character, Character>() {{
            put('{', '}');
            put('(', ')');
            put('[', ']');
        }};

        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            Character character = s.charAt(i);
            // 左括号进栈
            if (map.keySet().contains(character)) {
                stack.push(character);
            } else {
            // 右括号
                if (stack.isEmpty()) {
                    // 空栈情况下出现又括号直接返回false
                    return false;
                }
                // 出栈并对比是否为对应的右括号
                Character right = map.get(stack.pop());
                if (character.charValue() != right.charValue()) {
                    return false;
                }
            }
        }
        // 空栈即为正确
        return stack.isEmpty();
    }
}
```
