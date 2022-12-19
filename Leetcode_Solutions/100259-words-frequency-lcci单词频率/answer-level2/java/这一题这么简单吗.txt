### 解题思路
map统计频率即可

### 代码

```java
class WordsFrequency {
    Map<String, Integer> map = new HashMap<>();

    public WordsFrequency(String[] book) {
        for (String string : book) {
            map.put(string, map.getOrDefault(string, 0) + 1);
        }
    }

    public int get(String word) {
        if (map.containsKey(word)) {
            return map.get(word);
        } else {
            return 0;
        }
    }
}

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency obj = new WordsFrequency(book);
 * int param_1 = obj.get(word);
 */
```