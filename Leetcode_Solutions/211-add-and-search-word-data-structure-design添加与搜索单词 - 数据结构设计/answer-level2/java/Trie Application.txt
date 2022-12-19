    
    class WordDictionary {
        public class Node{
            boolean isEnd;
            Node[] next;
            public Node() {
                isEnd = false;
                next = new Node[26];
            }
        }
        
        public Node root; 
        /** Initialize your data structure here. */
        public WordDictionary() {
            root = new Node();
        }
        
        /** Adds a word into the data structure. */
        public void addWord(String word) {
            Node cur = root;
            int index = 0;
            for(int i = 0;i < word.length();i++) {
                index = word.charAt(i) - 'a';
                if(cur.next[index] == null) {
                    cur.next[index] = new Node();
                }
                cur = cur.next[index];
            }
            cur.isEnd = true;
        }
        
        /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
        public boolean search(String word) {
            return dfs(root, word, 0);
        }

        public boolean dfs(Node root, String word, int i) {
            if(i == word.length()) {
                return root.isEnd ? true : false;
            }
            boolean res = false;
            if(word.charAt(i) != '.' && root.next[word.charAt(i) - 'a'] != null) {
                res = dfs(root.next[word.charAt(i) - 'a'], word, i + 1);
            }
            if(word.charAt(i) == '.') {
                for(int j = 0;j < 26;j++) {
                    if(root.next[j] != null) {
                        res |= dfs(root.next[j], word, i + 1);
                    }
                }
            }
            return res;
        }
    }
