用字符长度筛选一下，然后再对比

```java
class WordDictionary {

    HashMap<Integer, HashSet<String>> l = new HashMap<Integer, HashSet<String>>();

    /**
     * Initialize your data structure here.
     */
    public WordDictionary() {

    }

    /**
     * Adds a word into the data structure.
     */
    public void addWord(String word) {
        int len = word.length();
        l.putIfAbsent(len, new HashSet<>());
        l.get(len).add(word);
    }

    /**
     * Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
     */
    public boolean search(String word) {

        int length = word.length();
        if (!l.containsKey(length))return false;
        HashSet<String> set = l.get(length);
        long count = set.stream()
                .filter(s -> cmp(s, word))
                .count();
        System.err.println(word + ":" + count);
        return count > 0;
    }

    private boolean cmp(String w1, String w2) {
        if (w1.length() != w2.length()) {
            return false;
        }

        boolean ok = true;
        for (int i = 0; i < w1.length(); i++) {
            char c1 = w1.charAt(i);
            char c2 = w2.charAt(i);
            if (c1 == '.' || c2 == '.') continue;
            if (c1 != c2) {
                ok = false;
                break;
            }
        }
        return ok;
    }


    public static void main(String[] args) {
        WordDictionary w = new WordDictionary();
        w.addWord("bad");
        w.addWord("dad");
        w.addWord("mad");
        w.search("pad");
        w.search("bad");
        w.search(".ad");
        w.search("b..");
    }
}
```
