### 解题思路
此题比较简单，使用一个HashMap统计词频即可。

### 代码

```java
class WordsFrequency {

    Map<String,Integer> map;
    public WordsFrequency(String[] book) {
        map = new HashMap<>();
        for(String s:book){
            map.put(s,map.getOrDefault(s,0)+1);
        }
    }
    
    public int get(String word) {

        return map.getOrDefault(word,0);
    }
}

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency obj = new WordsFrequency(book);
 * int param_1 = obj.get(word);
 */
```