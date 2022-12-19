执行用时 :786 ms, 击败了62.96%的用户。
内存消耗 :149.1 MB,击败了80.00%的用户。
```
class WordFilter {
    String[] words;
    Map<Character, List<String>> map = new HashMap<>();
    Map<Character, List<Integer>> indexMap = new HashMap<>();
    public WordFilter(String[] words) {
        this.words = words;
        //根据单词首字母分开存放
        for(int i = 0; i < words.length; i++){
            char c = words[i].charAt(0);
            if(map.containsKey(c)){
                map.get(c).add(words[i]);
                indexMap.get(c).add(i);
            }else{
                List<String> l1 = new ArrayList<>();
                l1.add(words[i]);
                map.put(c, l1);
                List<Integer> l2 = new ArrayList<>();
                l2.add(i);
                indexMap.put(c, l2);
            }
        }
    }
    
    public int f(String prefix, String suffix) {
        if(prefix == null || prefix.equals("")){//没有前缀条件，直接搜索后缀
            for(int i = words.length-1; i>=0; i--){
                if(words[i].endsWith(suffix)){
                    return i;
                }
            }
        }else{//从相同首字母的单词中搜索
            char c = prefix.charAt(0);
            if(!map.containsKey(c)){
                return -1;
            }
            List<String> l1 = map.get(c);
            List<Integer> l2 = indexMap.get(c);
            for(int i = l1.size()-1; i>=0; i--){
                if(l1.get(i).startsWith(prefix) && l1.get(i).endsWith(suffix)){
                    return l2.get(i);
                }
            }
        }
        
        return -1;
    }
}
```