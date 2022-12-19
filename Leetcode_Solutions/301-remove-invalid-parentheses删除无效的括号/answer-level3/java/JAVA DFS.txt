# 使用哈希表去重的版本，效率较低
（执行用时 :123 ms, 在所有 Java 提交中击败了32.37%的用户）
```
    public List<String> removeInvalidParentheses(String s) {
        int left = 0;
        int right = 0;
        int count = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                left += 1;
            } else if (c == ')') {
                if (left > 0) {
                    left -= 1;
                } else {
                    right += 1;
                }
            }
        }
        count = left + right;
        Set<String> set = new HashSet<>();
        dfs(s, 0, set, new StringBuilder(""), count);
        return new ArrayList<String>(set);
    }
    
    private boolean isValid(String s) {
        int count = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                count += 1;
            }
            if (c == ')' && count-- == 0) {
                return false;
            }
        }
        return count == 0;
    }

    private void dfs(String s, int i, Set<String> set, StringBuilder sb, int count) {
        if (count < 0) {
            return;
        } 
        if (i == s.length()) {
            if (count == 0) {
                if (isValid(sb.toString())) {
                    set.add(sb.toString());
                }
            }
            return;
        }
        char c = s.charAt(i);
        int len = sb.length();
        if (c == '(' || c == ')') {
            /* do not reverse those two lines, otherwise you need to reset
             * the length of stringbuilder.
             */
            dfs(s, i + 1, set, sb, count - 1);          //not use ( or )
            dfs(s, i + 1, set, sb.append(c), count);    //use ( or )
        } else {
            dfs(s, i + 1, set, sb.append(c), count);    //pass other character
        }
        sb.setLength(len);                              //backtrack 
    }
```
# 优化重构后的版本，效率高，也更好理解
（执行用时 :6 ms, 在所有 Java 提交中击败了81.50%的用户）
```
    public List<String> removeInvalidParentheses(String s) {
        int leftParentheses = 0;
        int rightParentheses = 0;
        char[] str = s.toCharArray();
        for (char c : str) {
            if (c == '(') {
                leftParentheses += 1;
            } else if (c == ')') {
                if (leftParentheses > 0) {
                    leftParentheses -= 1;
                } else {
                    rightParentheses += 1;
                }
            }
        }
        List<String> ans = new ArrayList<>();
        dfs(s, leftParentheses, rightParentheses, new StringBuilder(s), 0, ans);
        return ans;
    }
    
    private boolean isValid(String s) {
        int count = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                count += 1;
            }
            if (c == ')') {
                count -= 1;
            }
            if (count < 0) {
                return false;
            }
        }
        return count == 0;
    }
    
    private void dfs(String s, int l, int r, StringBuilder sb, int start, List<String> ans) {
        if (l == 0 && r == 0 && isValid(sb.toString())) {
            ans.add(sb.toString());
            return;
        }
        
        for (int i = start; i < s.length(); i += 1) {
            if (i != start && s.charAt(i) == s.charAt(i - 1)) {
                continue;
            }
            
            if (s.charAt(i) == '(' || s.charAt(i) == ')') {
                sb = new StringBuilder(s);
                sb.deleteCharAt(i);
                if (r > 0 && s.charAt(i) == ')') {
                    dfs(sb.toString(), l, r - 1, sb, i, ans);
                } else if (l > 0 && s.charAt(i) == '(') {
                    dfs(sb.toString(), l - 1, r, sb, i, ans);
                }
            } 
        }
    }
```


