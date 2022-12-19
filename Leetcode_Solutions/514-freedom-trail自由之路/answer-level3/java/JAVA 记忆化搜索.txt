执行用时 :9 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :36.4 MB, 在所有 java 提交中击败了100.00%的用户

+ 对ring建图
+ 记忆化搜索，利用当前的ring位置和当前key字符的位置作为状态标志

代码如下
```
    public int findRotateSteps(String ring, String key) {
        char[] rings=ring.toCharArray();
        List<Integer>[] rs=new List[26];
        for (int i=0;i<26;i++)rs[i]=new ArrayList<>();
        for (int i=0;i<rings.length;i++)
        {
            rs[rings[i]-'a'].add(i);
        }

        char[] keys=key.toCharArray();
        int[][] dp=new int[ring.length()+1][key.length()+1];
        for (int i=0;i<dp.length;i++) Arrays.fill(dp[i],-1);

        return slove(0,0,keys,rs,dp,ring.length());
    }

    private final static int MAX=Integer.MAX_VALUE>>1;
    private int slove(int r_idx, int k_idx, char[] keys, List<Integer>[] rs, int[][] dp,final int rlen) {
        if(k_idx==keys.length)return 0;
        if(dp[r_idx][k_idx]!=-1)return dp[r_idx][k_idx];
        int res=MAX;
        for (int i:rs[keys[k_idx]-'a'])
        {
            int t=1+Math.min(Math.abs(r_idx-i),Math.min(Math.abs(i+rlen-r_idx),Math.abs(r_idx+rlen-i)));
            t+=slove(i,k_idx+1,keys,rs,dp,rlen);

            res=Math.min(res,t);
        }
        return dp[r_idx][k_idx]=res;
    }
```

