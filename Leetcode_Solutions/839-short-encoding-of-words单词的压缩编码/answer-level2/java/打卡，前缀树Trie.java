    // 其实是找后缀与完全相等的词汇去掉
    class Solution {
        public class Node{
            boolean isEnd;
            Node[] next;
            public Node() {
                isEnd = false;
                next = new Node[26];
            }
        }
        
        public class Trie{
            Node root;
            public Trie() {
                root = new Node();
            }
            
            public void insert(String s) {
                Node cur = root;
                for(int i = s.length() - 1;i >= 0;i--) {
                    if(cur.next[s.charAt(i) - 'a'] == null) {
                        cur.next[s.charAt(i) - 'a'] = new Node();
                    }
                    cur = cur.next[s.charAt(i) - 'a'];
                }
                cur.isEnd = true;
            }

            public boolean contain(String s) {
                Node cur = root;
                for(int i = s.length() - 1;i >= 0;i--) {
                    if(cur.next[s.charAt(i) - 'a'] == null) {
                        return false;
                    }
                    cur = cur.next[s.charAt(i) - 'a'];
                }
                return cur.isEnd ? true : false;
            }
        }

        public int minimumLengthEncoding(String[] words) {
            int res = 0;
            Trie tree = new Trie();
            int[] count = new int[2];
            for(int i = 0;i < words.length;i++) {
                res += words[i].length();
                // 考虑去重
                if(!tree.contain(words[i])) {
                    tree.insert(words[i]);
                }else {
                    count[0] += words[i].length();
                    count[1]++;
                }
            }
            // dfs去后缀
            dfs(tree.root, 0, count);
            return res - count[0] + words.length - count[1];
        }

        public void dfs(Node root, int level, int[] count) {
            if(root.isEnd) {   // 为某个词的后缀
                for(int i = 0;i < 26;i++) {
                    if(root.next[i] != null) {
                        count[0] += level;
                        count[1]++;
                        break;
                    }
                }
            }
            for(int i = 0;i < 26;i++) {
                if(root.next[i] != null) {
                    dfs(root.next[i], level + 1, count);
                }
            }
        }
    }