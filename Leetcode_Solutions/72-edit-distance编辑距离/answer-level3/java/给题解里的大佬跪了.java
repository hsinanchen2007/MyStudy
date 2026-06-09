### 解题思路


### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
        int[][] dp=new int[word1.length()+1][word2.length()+1];

		dp[0][0]=0;
		for(int x=1;x<dp[0].length;x++){
			dp[0][x]=dp[0][x-1]+1;
		}
		for(int x=1;x<dp.length;x++){
			dp[x][0]=dp[x-1][0]+1;
		} 
		
		for(int x=1;x<dp.length;x++){//行
			for(int y=1;y<dp[0].length;y++){//列
				if(word1.charAt(x-1)==word2.charAt(y-1)){
					dp[x][y]=dp[x-1][y-1];
				}else{
					dp[x][y]=Math.min(Math.min(dp[x-1][y],dp[x][y-1]),dp[x-1][y-1])+1;
				}
				
				
			}
		}
		
		
		
		
		
		 return dp[word1.length()][word2.length()];
    }
}
```