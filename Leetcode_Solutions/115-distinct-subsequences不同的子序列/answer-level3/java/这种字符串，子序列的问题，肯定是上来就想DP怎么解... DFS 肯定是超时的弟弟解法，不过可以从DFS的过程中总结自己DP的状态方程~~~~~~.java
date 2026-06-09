这种字符串，子序列的问题，肯定是上来就想DP怎么解... DFS 肯定是超时的弟弟解法，不过可以从DFS的过程中总结自己DP的状态方程~~~~~~
```
class Solution {
    
    // dp f(i,j) 表示前i个T，在前 j个S中出现的次数
    
    //
    
    public int numDistinct(String ss, String ts) {
        if(ss == null || ss.length() == 0 || ts == null || ts.length() == 0){
            return 0;
        }
        char[] s = ss.toCharArray();
        char[] t = ts.toCharArray();
        int[][] mem = new int[t.length][s.length];
        mem[0][0] = t[0] == s[0] ? 1 : 0;
        for(int i = 1; i < s.length; i++){
            mem[0][i] = mem[0][i-1];
            if(s[i] == t[0]){
                mem[0][i] += 1;
            }
        }
        //System.out.println(Arrays.toString(mem[0]));
        for(int i = 1; i < t.length; i++){
            for(int j = i; j < s.length; j++){
                mem[i][j] = mem[i][j-1];
                if(t[i] == s[j]){
                    mem[i][j] += mem[i-1][j-1];
                }
            }
            //System.out.println(Arrays.toString(mem[i]));
        }
        return mem[t.length-1][s.length-1];
    }
}
```
