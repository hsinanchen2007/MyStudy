执行结果：
通过
显示详情
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
33.8 MB
, 在所有 Java 提交中击败了
9.48%
的用户```
class Solution {
    Map<Integer,Integer> map = new HashMap<>();
    public int numTrees(int n) {
        if(n==0)return 0;
        int[] dp = new int[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=n; i++){
            int sum=0;
            for(int j = 1; j<=i; j++){
                int left = val(dp,1,j-1);
                int right = val(dp,j+1,i);
                sum+=left*right;
            }
            dp[i]=sum;
        }
        return dp[n];
    }
    private int val(int[] dp, int s,int e){
        if(s>=e)return 1;
        return dp[e-s+1];
    }
    
}
```
