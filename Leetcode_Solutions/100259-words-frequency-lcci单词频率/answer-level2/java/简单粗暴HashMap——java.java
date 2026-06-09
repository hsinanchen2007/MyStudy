```java
class WordsFrequency {
    private HashMap<String, Integer> map = new HashMap<>();

    public WordsFrequency(String[] book) {
        for (String str : book)
            map.merge(str, 1, (old_val, new_val) -> old_val + new_val);
    }

    public int get(String word) {
        return map.getOrDefault(word, 0);
    }
}
```
