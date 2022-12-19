执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :36.4 MB, 在所有 Java 提交中击败了83.19%的用户

```
class Solution {
    public int[] shortestToChar(String S, char C) {
        int len = S.length();
        int[] ans = new int[len];
        int prevPos = -1;
        
        for (int i = 0; i < len; i++) {
            if (S.charAt(i) == C) {
                ans[i] = 0;
                int stopPos = ((prevPos == -1) ? 0 : (i+ prevPos + 1) / 2);
                for (int j = i - 1; j >= stopPos; j--) ans[j] = i - j;
                prevPos = i;
            } else {
                if(prevPos != -1) ans[i] = i- prevPos; 
            };
        };
        return ans;
        
    }
}
```
