回溯，需要一直保证str中左括号数量大于等于右括号数量

```
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        if (n <= 0) {
            return res;
        }
        backTrace(n, n, new StringBuilder(), res);
        return res;
    }
    // left:左括号剩余个数; right:右括号剩余个数; 需要保证剩余的右括号比左括号多，才能拼出有效的括号对
    private void backTrace(int left, int right, StringBuilder str, List<String> res) {
        if (left > right) {
            return;
        }
        if (right == 0) {
            res.add(str.toString());    
            return;        
        }
        if (left > 0) {
            str.append('(');
            backTrace(left - 1, right, str, res);
            str.deleteCharAt(str.length() - 1);
        }
        if (right > 0) {
            str.append(')');
            backTrace(left, right - 1, str, res);
            str.deleteCharAt(str.length() - 1);
        }

    }
```