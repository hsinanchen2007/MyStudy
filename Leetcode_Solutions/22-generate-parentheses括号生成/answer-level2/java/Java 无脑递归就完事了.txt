```java
class Solution {
    List<String> res;
    int n;
    public List<String> generateParenthesis(int n) {
        res = new ArrayList<String>();
        this.n = n;
        helper(0, 0, "");
        return res;
    }

    void helper(int left, int right, String cur) {
        if (left == n && right == n ) {
            res.add(cur);
            return;
        }
        if (left > n || right > n || right > left) return;
        helper(left + 1, right, cur + "(");
        helper(left, right + 1, cur + ")");
    }
}
```