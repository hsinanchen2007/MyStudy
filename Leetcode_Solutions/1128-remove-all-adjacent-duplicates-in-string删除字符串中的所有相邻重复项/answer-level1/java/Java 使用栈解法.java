```java
class Solution {
    public String removeDuplicates(String S) {
        Stack<Character> st = new Stack<Character>();
        for (int i = 0; i < S.length(); i ++) {
            if (!st.isEmpty() && st.peek() == S.charAt(i)) {
                st.pop();
                continue;
            } else {
                st.push(S.charAt(i));
            }
        }
        StringBuilder sb = new StringBuilder();
        for (char c : st) {
            sb.append(c);
        }
        return sb.toString();
    }
}
```