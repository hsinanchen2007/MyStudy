思路：显而易见回溯法。
<br/><br/>
代码：
```
class Solution {
    List<String> ans = new ArrayList<>();
    public List<String> letterCasePermutation(String S) {
        dfs(new StringBuilder(S),0);
        return ans;
    }
    
    private void dfs(StringBuilder s,int cur) {
        if (cur == s.length()) {
            ans.add(s.toString());
            return;
        }
        
        if (Character.isDigit(s.charAt(cur))) {
            dfs(s,cur + 1);
        } else {
            char ch = s.charAt(cur);
            s.setCharAt(cur,Character.toLowerCase(ch));
            dfs(s,cur + 1);
            s.setCharAt(cur,Character.toUpperCase(ch));
            dfs(s,cur + 1);
        }
    }
}
```