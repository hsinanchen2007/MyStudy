前缀树(字典树)：多叉树表示字典序的字符串的查询，优势每次查询的时间复杂度是字符串的长度，与字符数量无关，即是常数级的时间复杂度。
实现方式是多叉树，每个节点存储字符是否出现作为字符串的最后一个字符，如果某一层的字母没出现过则是null。
class Trie {
    public class TrieNode {
        public boolean end;
        public TrieNode[] nexts;
        
        public TrieNode() {
            end = false;
            nexts = new TrieNode[26];
        }
    }
    public TrieNode root;
    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode(); 
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {        
        char[] str = word.toCharArray();
        int index = 0;
        TrieNode cur = root;
        
        for(int i = 0; i < str.length; i++) {
            index = str[i] - 'a';
            if(cur.nexts[index] == null) {
                cur.nexts[index] = new TrieNode();
            }
            
            cur = cur.nexts[index];
        }
        cur.end = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        char[] str = word.toCharArray();
        int index = 0;
        TrieNode cur = root;
        
        for(int i = 0; i < str.length; i++) {
            index = str[i] - 'a';
            if(cur.nexts[index] == null) {
                return false;
            }
            
            cur = cur.nexts[index];
        }
        return cur.end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        char[] str = prefix.toCharArray();
        int index = 0;
        TrieNode cur = root;
        
        for(int i = 0; i < str.length; i++) {
            index = str[i] - 'a';
            if(cur.nexts[index] == null) {
                return false;
            }
            
            cur = cur.nexts[index];
        }
        return true;
    }
}
