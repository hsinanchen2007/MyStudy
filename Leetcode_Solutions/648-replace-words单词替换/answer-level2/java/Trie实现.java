正常版本直接用双重循环很容易解决，不过该题目可以使用前缀树来实现，找到前缀树里第一个前缀然后替换，如果找不到前缀就使用原字符串。
```
class Solution {
    public String replaceWords(List<String> dict, String sentence) {
        Trie trie = buildTrie(dict);
        StringBuilder sb = new StringBuilder();
        String[] str = sentence.split("\\s+");
        for(int i = 0;i < str.length;i++){
            sb.append(findRoot(str[i], trie));
            sb.append(" ");
        }
        return sb.substring(0, sb.length()-1);
    }
    public Trie buildTrie(List<String> dict){
        Trie trie = new Trie();
        for(int i = 0;i < dict.size();i++){
            String tmp = dict.get(i);
            trie.add(tmp);
        }
        return trie;
    }
   //核心方法，找前缀
    public String findRoot(String s,Trie trie){
        Node cur = trie.root;
        StringBuilder sb = new StringBuilder();
        for(int i = 0;i < s.length();i++){
            char c = s.charAt(i);
            sb.append(c);
            if(cur.map.get(c) == null)
                    return s;
            else{
                cur = cur.map.get(c);
                if(cur.isWord)
                    return sb.toString();   
            }
        }
        return s;
    }
}
class Trie{
    public Node root;

    public Trie() {
        this.root = new Node();
    }

    public void add(String s){
        Node cur = root;
        for(int i = 0;i < s.length();i++){
            char c = s.charAt(i);
            if(cur.map.get(c) == null)
                cur.map.put(c, new Node());
            cur = cur.map.get(c);
        }
        cur.isWord = true;
    }
     public boolean contains(String s){
        Node cur = root;
        for(int i = 0;i < s.length();i++){
            char c = s.charAt(i);
            if(cur.map.get(c) == null)
                return false;
            cur = cur.map.get(c);
        }
        return cur.isWord;
    }
}
class Node{
    public boolean isWord;
    public HashMap<Character,Node> map;

    public Node(boolean isWord) {
        this.isWord = isWord;
        this.map = new HashMap<>();
    }
    public Node(){
        this(false);
    }
}
```