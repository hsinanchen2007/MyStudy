动态规划保存记录
```
import java.util.*;
class Solution {
    public int minInsertions(String s) {
        int[][] hash = new int[s.length()][s.length()];
        for(int i = 0; i < s.length()-1; i++) {
            for(int j = 0; j < s.length(); j++) {
                if(i == j || Math.abs(i - j) == 1 && s.charAt(i) == s.charAt(j)) {
                    hash[i][j] = 0;
                }else
                    hash[i][j] = -1;
            }
        }
        return minInsertProcess(s, 0, s.length() - 1, hash);
    }
    public int minInsertProcess(String s, int start, int end, int[][] hash) {
        if(hash[start][end] != -1) {
            return hash[start][end];
        }
        int a = s.charAt(start);
        int b = s.charAt(end);
        if(a == b) {
            hash[start][end] = minInsertProcess(s, start + 1, end - 1, hash);
        }else {
            hash[start][end] = 1 + Math.min(minInsertProcess(s, start + 1, end, hash), minInsertProcess(s, start, end - 1, hash));
        }
        return hash[start][end];
    }
}
```
