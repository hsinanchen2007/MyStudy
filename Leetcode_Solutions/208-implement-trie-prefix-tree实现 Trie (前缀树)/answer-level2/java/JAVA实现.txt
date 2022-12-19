参考官方题解，构造一个前缀树，树的节点继承自HashMap。
增加isEnd标志位，insert了"apple"，"app"的情况在app的末尾要设置isEnd。


```JAVA
class Trie {

    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void insert(String word) {
        int length = word.length();

        TrieNode node = root;

        for (int i = 0; i < length; i++) {
            char c = word.charAt(i);
            if (node.containsKey(c)) {
                node = node.get(c);
            } else {
                node = node.put(c);
            }
        }
        node.isEnd=true;
    }


    public boolean search(String word) {
        int length = word.length();
        TrieNode node = root;

        for (int i = 0; i < length; i++) {
            char c = word.charAt(i);
            if (!node.containsKey(c)) {
                return false;
            } else {
                node = node.get(c);
            }
        }
        return node.isEnd;
    }


    public boolean startsWith(String prefix) {
        int length = prefix.length();
        TrieNode node = root;

        for (int i = 0; i < length; i++) {
            char c = prefix.charAt(i);
            if (!node.containsKey(c)) {
                return false;
            } else {
                node = node.get(c);
            }
        }
        return true;
    }


    private class TrieNode extends HashMap<Character, TrieNode> {
        boolean isEnd=false;

        public TrieNode put(char c) {
            TrieNode node = new TrieNode();
            super.put(c, node);
            return node;
        }
    }

    public static void main(String[] args) {
        Trie t = new Trie();
        t.insert("apple");
        System.out.println("t.search(\"apple\") = " + t.search("apple"));
        System.out.println("t.search(\"app\") = " + t.search("app"));
        System.out.println("t.startsWith(\"app\") = " + t.startsWith("app"));
        t.insert("app");
        System.out.println("t.search(\"app\") = " + t.search("app"));
    }
}
```
