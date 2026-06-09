和大家写的差不多
就是相当于将所有相似的词都合并成相同的集合，在这个集合中每个词的parent都一样
最后判断words1和words2中的每个词的parent是否一样就行了
```
class Solution {
    Map<String, String> map = new HashMap<>();
    public boolean areSentencesSimilarTwo(String[] words1, String[] words2, List<List<String>> pairs) {
        if(words1.length != words2.length)
            return false;
        for(List<String> pair: pairs)
            union(pair.get(0), pair.get(1));
        for(int i = 0; i < words1.length; i++)
        {
            if(!find(words1[i]).equals(find(words2[i])))
                return false;
        }
        return true;
    }
    
    public void union(String word1, String word2) {
        String x = find(word1);
        String y = find(word2);
        if(!x.equals(y))
            map.put(x, y);
    }
    
    public String find(String word) {
        while(map.containsKey(word) && map.get(word) != word)
            word = map.get(word);
        return word;
    }
}
```
