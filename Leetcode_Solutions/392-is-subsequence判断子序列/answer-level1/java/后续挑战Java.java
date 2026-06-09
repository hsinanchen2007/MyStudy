建一个n*26的矩阵。
先处理矩阵的最后一行，然后直接把最后一行copy到倒数第二行，再更新由于最后一个元素导致的倒数第二行的元素的变更即可。
然后我们就可以跳着找了，找不到就证明应该返回false了。
注意，用这种办法，我们要先确认s的第一个字符在不在t中，如果不在，就无从谈起了。 在的话，才能用dp跳着找。

```
class Solution {
    public boolean isSubsequence(String s, String t){
        if(s.length() == 0) return true;
        if(s.length() > t.length()) return false;
        int[][] dp = new int[t.length()][26];
        Arrays.fill(dp[t.length()-1],-1);
        for(int i = t.length()-2; i > -1; i--){
            dp[i] = Arrays.copyOf(dp[i+1],26);
            dp[i][t.charAt(i+1)-'a'] = i+1;
        }
        int ptr = 0,i = 0;
        for(; i < t.length(); i++){
            if(t.charAt(i) == s.charAt(0)){
                ptr = i;
                break;
            }
        }
        if(i == t.length()) return false;
        char[] cs = s.toCharArray();
        for(char c : Arrays.copyOfRange(s.toCharArray(),1,s.length())){
            if(dp[ptr][c-'a'] == -1){
                return false;
            }
            ptr = dp[ptr][c-'a'];
        }
        return true;
    }
}
```
