### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int MinDistance(string word1, string word2) {
        int n=word1.Length;
        int m=word2.Length;
        //其中一个是空串
        if(n*m==0){
            return n+m;
        }

        int[,] dp = new int[n+1,m+1];
        //A串为空，初始化边界
        for(int i=0;i<=m;i++){
            dp[0,i]=i;
        }
        //B串为空，初始化边界
        for(int i=0;i<=n;i++){
            dp[i,0]=i;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //A串插入
                int left=dp[i,j-1]+1;
                //B串插入
                int right=dp[i-1,j]+1;
                //A串替换
                int edit=dp[i-1,j-1];
                if(word1[i-1]!=word2[j-1]){
                    edit++;
                }
                dp[i,j]=Math.Min(left,Math.Min(right,edit));
            }
        }
        return dp[n,m];
    }
}
```