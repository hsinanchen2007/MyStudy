```
class Solution {
    List<String> res = new ArrayList<>();
    public List<String> generateParenthesis(int n) {
        if (n == 0)
            return res;
        dfs("", 0, 0, n);
        return res;
    }
    public void dfs(String s, int left, int right, int n) {
        if (left == n && right == n) {
            res.add(s);
            return ;
        }
        if (right > left)
            return ;
        if (left < n)
            dfs(s + "(", left + 1, right, n);
        if (right < n)
            dfs(s + ")", left, right + 1, n);
    }
}
```
