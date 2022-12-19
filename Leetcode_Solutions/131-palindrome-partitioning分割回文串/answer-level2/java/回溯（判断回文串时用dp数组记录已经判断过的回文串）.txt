### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private String s;
    private int n;
    private int[][] dp;
    private List<List<String>> res = new ArrayList<>();
    public List<List<String>> partition(String s) {
        if (s == null || s.length() == 0) return res;
        this.s = s;
        this.n = s.length();
        this.dp = new int[n][n];
        List<Integer> now = new ArrayList<>();
        now.add(0);
        dfs(0, now);
        return res;
    }

    private void dfs(int index, List<Integer> now) {
        if (index == n) {
            //now.add(n);
            res.add(buildList(now));
            //now.remove(now.size() - 1);
            return ;
        }
        for (int i = index; i < n; i++) {
            if (isPalindrome(index, i)) {
                now.add(i + 1);
                dfs(i + 1, now);
                now.remove(now.size() - 1);
            }
        }
    }

    private List<String> buildList(List<Integer> iList) {
        List<String> sList = new ArrayList<>();
        for (int i = 0; i < iList.size() - 1; i++) {
            sList.add(s.substring(iList.get(i), iList.get(i + 1)));
        }
        return sList;
    }

    private boolean isPalindrome(int begin, int end) {
        if (dp[begin][end] == 1) return false;
        if (dp[begin][end] == 2) return true;
        //System.out.println(s.substring(begin, end + 1));
        int num = (end - begin + 1) / 2;
        for (int i = 0; i < num; i++) {
            if (s.charAt(begin + i) != s.charAt(end - i)) {
                dp[begin][end] = 1;
                return false;
            }
        }
        //System.out.println(s.substring(begin, end + 1));
        dp[begin][end] = 2;
        return true;
    }
}
```