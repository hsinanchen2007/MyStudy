```
class Trie {

    private final NavigableSet<String> set = new TreeSet<>();
    
    public Trie() {
    }

    public void insert(String word) {
        set.add(word);
    }

    public boolean search(String word) {
        return set.contains(word);
    }

    public boolean startsWith(String prefix) {
        String s = set.ceiling(prefix);
        if(s == null) {
            return false;
        }
        
        return s.startsWith(prefix);
    }
}
```
ceiling方法是返回大于等于字符串的字符串，找到之后只需要判断该字符串是否以prefix开头就可以了。此外如果是后缀树，只需要逆序存储word即可，即new StringBuilder(word).reverse().toString()，然后在查找prefix时也将该字符串逆序之后再查找。