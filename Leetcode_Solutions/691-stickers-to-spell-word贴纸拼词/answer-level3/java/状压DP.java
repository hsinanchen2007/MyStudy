思路：定义dp[i]：表示状态为i时所用的最少贴纸数量。
其中i的二进制每一位若为1表示target的该位字符已经拼出来了。
```
class Solution {
    public int minStickers(String[] stickers, String target) {
        
    	int[] a=new int[26];
    	int[] dp=new int[1<<target.length()];
    	int[][] b=new int[stickers.length][26];
    	
    	for(int i=0;i<stickers.length;i++)
    		for(int j=0;j<stickers[i].length();j++) {
    			a[stickers[i].charAt(j)-'a']++;
    			b[i][stickers[i].charAt(j)-'a']++;
    		}
    	
    	for(int i=0;i<target.length();i++)
    		if(a[target.charAt(i)-'a']==0)
    			return -1;
    	
    	for(int i=1;i<(1<<target.length());i++)
    		dp[i]=-1;
    	
    	for(int i=0;i<(1<<target.length());i++) {
			if(dp[i]!=-1) {
				for(int j=0;j<stickers.length;j++) {
					int state=i;
					for(int k=0;k<26;k++) a[k]=b[j][k];
					for(int k=0;k<target.length();k++) {
						if(((1<<k)&i)!=0) continue;
						if(a[target.charAt(k)-'a']==0) continue;
						state|=(1<<k); 
						a[target.charAt(k)-'a']--;
					}
					if(dp[state]==-1 || dp[state]>dp[i]+1)
						dp[state]=dp[i]+1;
				}
			}
    	}
    	
    	return dp[(1<<target.length())-1];
    }
}
```
