```
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] dp = new int[n];

        List<Integer> row = triangle.get(n-1);//获取最后一行的数据存入dp数组中
        for(int i=0;i<row.size();i++){
            dp[i]=row.get(i);
        }       

        for(int i=n-2;i>=0;i--){//从倒数第二行开始
            List<Integer> currentRow = triangle.get(i);
            for(int j=0;j<=i;j++){//dp值刷新为当前值加上下一行相邻数据之间的最小值
                dp[j]=currentRow.get(j)+Math.min(dp[j],dp[j+1]);
            }
        }
        
        return dp[0];//此时dp[0]即为最小路径和
    }
}

```
