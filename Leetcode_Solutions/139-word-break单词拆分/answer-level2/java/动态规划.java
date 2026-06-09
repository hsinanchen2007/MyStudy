该问题是字符串版本的背包问题，可以将字符串s看作是背包，将字符串数组wordDict看作是物品列表，并且物品可以被重复使用，且在这个问题中，不需要考虑放进背包物品的最大化，只需要背包是否可以被装满。
因此，可以使用背包问题的解题思路建模

状态：```dp[s] 为子串s[0...i]是否可以使用wordDict`划分` ```
状态转移方程为
```
dp[s] = (dp[s] contains wordDict[0] && dp[s.remove(wordDict[0])]) 
|| (dp[s] contains wordDict[1] && dp[s.remove(wordDict[1])]) ...
|| (dp[s] contains wordDict[n-1] && dp[s.remove(wordDict[n-1])])
```

状态转移方程含义为,对于每个子串，看该子串是否包含字符串数组wordDict中的某个字符，如果包含，则看该子串出去该字符后剩余的子串是否能被wordDict拆分

由于这里的状态是字符串，方便起见，不再用数组来存储状态，而是用hashMap存储，key为子串，value为该子串是否可以被拆分

```
public boolean wordBreak(String s, List<String> wordDict) {
        HashMap<String,Boolean> dp = new HashMap<>();
        dp.put("",true);

        for(int i=1;i<=s.length();i++){
            String subS = s.substring(0,i);
            boolean subRes = false;
            for(String word:wordDict){
                if(subS.contains(word)){
                    String lastS = subS.substring(0,subS.lastIndexOf(word))+subS.substring(subS.lastIndexOf(word)+word.length());
                    if(dp.getOrDefault(lastS, false)){
                        subRes = true;
                        break;
                    }
                }
            }
            dp.put(subS,subRes);
        }
        return dp.getOrDefault(s,false);
    }

```