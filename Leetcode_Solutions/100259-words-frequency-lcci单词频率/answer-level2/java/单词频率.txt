### 解题思路
    哈希表的应用，使用哈希map构造键值对，key的值为单词，value的值为单词出现的频率。
### 代码

```java
class WordsFrequency {
    //Java语言的哈希表法
    private Map<String,Integer> map=new HashMap<>();
    public WordsFrequency(String[] book) {
        for(String name:book)
        {
            map.put(name,map.getOrDefault(name,0)+1);
        }
        
    }
    
    public int get(String word) {
        return map.get(word)==null ? 0:map.get(word);
        
    }
}

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency obj = new WordsFrequency(book);
 * int param_1 = obj.get(word);
 */
```