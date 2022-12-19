```
int min;
    int max;
    public List<String> wordBreak(String s, List<String> wordDict) {
        List<String> list = new ArrayList<>();
        if(wordDict.size() == 0){
            return list;
        }
        Set<String> set = new HashSet<>(wordDict);
        min = wordDict.get(0).length();
        max = wordDict.get(0).length();
        for(String string : wordDict) {
        	min = Math.min(min, string.length());
        	max = Math.max(max, string.length());
        }
        int[] isok = new int[s.length()]; // 0表示未完结，1表示可行，2表示不可行
        dfs(set, s, 0, list, "", isok);
        return list;
    }
    public boolean dfs(Set<String> set, String s, int index, List<String> list, String current, int[] isok){
        if(index == s.length()){
            list.add(current);
            return true;
        }
        if(index != 0){
            current += " ";
        }
        boolean flag = false;
        for(int j = index + max; j >= index + min; j--){
            if(j <= s.length() && isok[j - 1] != 2){
                String sub = s.substring(index, j);
                if(set.contains(sub) && dfs(set, s, j, list, current + sub, isok)){
                    flag = true;
                }
            }
        }
        if(index != 0) {
        	if(flag){
        		isok[index - 1] = 1;
        	}else{
        		isok[index - 1] = 2;
        	}
        }
        return flag;
    }
```
