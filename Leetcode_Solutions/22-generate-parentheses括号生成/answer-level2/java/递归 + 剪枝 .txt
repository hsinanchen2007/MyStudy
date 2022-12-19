```
class Solution {
    private List<String> res;
    public List<String> generateParenthesis(int n) {
        res = new ArrayList<>();
        helper(n, "", 0, 0);
        return res;
    }

    private void helper(int n, String pre, int left, int leftTotal) {
        if ( pre.length() == 2 * n && left == 0) {
            res.add(pre);
            return;
        }
        if (left <= 0) {
            helper(n, pre + "(", 1, leftTotal + 1);
        } else {
            if ( leftTotal < n) {
                helper(n, pre + "(", left + 1, leftTotal + 1);
            }
            helper(n, pre + ")", left - 1, leftTotal);
        }
    }
}
```
