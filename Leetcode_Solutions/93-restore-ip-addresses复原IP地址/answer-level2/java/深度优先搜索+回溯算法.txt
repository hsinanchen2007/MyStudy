```
//Java深度优先搜索
class Solution {

    public List<String> restoreIpAddresses(String s) {
        if (s == null || "".equals(s.trim())) {
            return Collections.emptyList();
        }
        List<String> ans = new LinkedList<>();
        dfs(ans, s, 0, new StringBuilder(), 0);
        return ans;
    }

    private void dfs(List<String> ans, String s, int start, StringBuilder ip, int num) {
        if (num > 4) {
            return;
        }
        if (start == s.length()) {
            if (num == 4) {
                ans.add(ip.substring(1));
            }
            return;
        }
        for (int end = start + 1; end <= s.length() && end <= start + 3; end++) {
            if (end - start > 1 && s.charAt(start) == '0') {
                return;
            }
            int n = Integer.parseInt(s.substring(start, end));
            if (n < 256) {
                ip.append(".").append(n);
                dfs(ans, s, end, ip, num + 1);
                ip.delete(ip.lastIndexOf("."), ip.length());
            }
        }
    }
}
```
