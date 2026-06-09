DFS 问题
```
    private Set<String> dp = new HashSet();
    public boolean wordBreak(String s, List<String> wordDict) {
        if(dp.contains(s)) return false; 
        if(s.length() == 0) return true;
        
        for(String str : wordDict){
            if(s.startsWith(str) && wordBreak(s.substring(str.length()), wordDict)){
                return true;
            }
        }
        
        dp.add(s);
        return false;
    }
```
