### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> generateParenthesis(int n) {
        char[] cur = new char[2 * n];
        List<String> ans = new ArrayList<>();
        backTracking(cur, 0, 0, 0, n, ans);
        return ans;
    }

    private void backTracking(char[] cur, int idx, int left, int right, int n, List<String> ans) {
        if (idx == n * 2) {
            ans.add(new String(cur));
        }
        if (right < n && left > right) {
            cur[idx++] = ')';
            backTracking(cur, idx, left, right + 1, n, ans);
            --idx;
        }
        if (left < n) {
            cur[idx++] = '(';
            backTracking(cur, idx, left + 1, right, n, ans);
            --idx;
        }
        return;
    }
}
```