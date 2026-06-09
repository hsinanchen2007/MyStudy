java StringBuilder 实现

```
class Solution {
    public String removeOuterParentheses(String S) {
        StringBuilder builder = new StringBuilder();
        int count = 0;
        for (int i=0; i<S.length(); i++) {
            if (S.charAt(i) == ')') {
                count--;
            }
            if (count >= 1) {
                builder.append(S.charAt(i));
            }
            if (S.charAt(i) == '(') {
                count++;
            }
        }
        return builder.toString();
    }
}
```