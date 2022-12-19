```
class Solution {
    public String removeOuterParentheses(String S) {
        if ("".equals(S)) return "";
        int count = 0;
        StringBuilder res = new StringBuilder();
        for (int i = 1; i < S.length(); i++) {
            if (S.charAt(i) == ')') {
                if (count == 0) {
                    i++;
                } else {
                    res.append(S.charAt(i));
                    count--;
                }
            } else {
                res.append(S.charAt(i));
                count++;
            }
        }
        return res.toString();
    }
}
```

