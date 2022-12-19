    // 节点不存值，路径上存值，节点里有flag标志是否为一个单词的结尾
    class Trie {
        public class Node{
            boolean isEnd;
            Node[] next;
            public Node(){
                isEnd = false;
                next = new Node[26];
            }
        }
        public Node root;

        /** Initialize your data structure here. */
        public Trie() {
            root = new Node();    // 先生成一个根节点，所有操作都是从根节点开始
        }
        
        /** Inserts a word into the trie. */
        public void insert(String word) {
            Node cur = root;
            for(int i = 0;i < word.length();i++) {
                Node temp = new Node();
                if(cur.next[word.charAt(i) - 'a'] == null) {
                    cur.next[word.charAt(i) - 'a'] = temp;
                    cur = temp;
                }else {
                    cur = cur.next[word.charAt(i) - 'a'];
                }
            }
            cur.isEnd = true;
        }
        
        /** Returns if the word is in the trie. */
        public boolean search(String word) {
            Node cur = root;
            for(int i = 0;i < word.length();i++) {
                if(cur.next[word.charAt(i) - 'a'] == null) {
                    return false;
                }
                cur = cur.next[word.charAt(i) - 'a'];
            }
            return cur.isEnd == true;
        }
        
        /** Returns if there is any word in the trie that starts with the given prefix. */
        public boolean startsWith(String prefix) {
            Node cur = root;
            for(int i = 0;i < prefix.length();i++) {
                if(cur.next[prefix.charAt(i) - 'a'] == null) {
                    return false;
                }
                cur = cur.next[prefix.charAt(i) - 'a'];
            }
            return true;
        }
    }