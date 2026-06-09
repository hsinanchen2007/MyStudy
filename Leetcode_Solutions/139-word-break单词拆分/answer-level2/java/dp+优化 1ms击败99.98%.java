```
class Solution {
    int min;
    int max;
	public boolean wordBreak(String s, List<String> wordDict) {
        if(wordDict.size() == 0){
            return false;
        }
        Set<String> set = new HashSet<>(wordDict);
        min = wordDict.get(0).length();
        max = wordDict.get(0).length();
        for(String string : wordDict) {
        	min = Math.min(min, string.length());
        	max = Math.max(max, string.length());
        }
        int[] dp = new int[s.length()];
        for(int i = 0; i < dp.length; i++){
            for(int j = i + 1 - min; j >= 0 && j >= i + 1 - max;j--){
                if(j == 0 || dp[j - 1] == 1){
                    String sub = s.substring(j, i + 1);
                    if(set.contains(sub)){
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        return dp[dp.length - 1] == 1;
    }    
}
```
