```
class Solution {
    Map<String, String> parent = new HashMap<>();
    Map<String, HashSet<String>> map = new HashMap<>();
    TreeSet<String> set = new TreeSet<>();
    public List<String> generateSentences(List<List<String>> synonyms, String text) {
        for(List<String> s: synonyms)
            union(s.get(0), s.get(1));
        
        for(List<String> s: synonyms)
        {
            String p = find(s.get(0));
            map.putIfAbsent(p, new HashSet<>());
            map.get(p).add(s.get(0));
            map.get(p).add(s.get(1));
        }
        String[] arr = text.split(" ");
        dfs(arr, 0, "");
        return new ArrayList<>(set);
    }
    
    public void dfs(String[] arr, int index, String s) {
        if(index == arr.length)
        {
            set.add(s.trim());
            return;
        }
        if(!parent.containsKey(arr[index]))
            dfs(arr, index + 1, s + " " + arr[index]);
        else
        {
            String p1 = find(arr[index]);
            HashSet<String> temp = map.get(p1);
            for(String t: temp)
                dfs(arr, index + 1, s + " " + t);
        }
    }
    
    public void union(String s1, String s2) {
        String s11 = find(s1);
        String s22 = find(s2);
        parent.put(s11, s22);
    }
    
    public String find(String s) {
        if(!parent.containsKey(s))
            parent.put(s, s);
        if(parent.get(s) != s)
            parent.put(s, find(parent.get(s)));
        return parent.get(s);
    }
}
```
