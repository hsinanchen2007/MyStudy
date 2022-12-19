### 解题思路
自定义TrieNode, 通过trieNode的递归操作, 实现trie树操作。

### 代码

```java
class Trie {
    TrieNode head;

    /** Initialize your data structure here. */
    public Trie() {
        head = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        head.insert(word, 0);
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        return head.search(word, 0, false);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        return head.search(prefix, 0, true);
    }

    class TrieNode {

        TrieNode[] children;

        public TrieNode () {
            //最后一个位置表示终止位，即到该节点结束
            children = new TrieNode[27];
        }

        //递归插入所有的数据
        public void insert(String s, int start) {
            if(start == s.length()) {
                //如果到该节点结束，则在终止位记录下。
                this.children[26] = new TrieNode();
                return;
            }
            char c = s.charAt(start);
            if(this.children[c - 'a'] == null) {
                this.children[c - 'a'] = new TrieNode();
            }
            this.children[c - 'a'].insert(s, start+1);
        }

        /**
            * 
            * @param s 要搜索的字符串
            * @param start 本次搜索的索引
            * @param prefix 是否是前缀匹配。 
            *               true表示trie数中出现s就返回成功, 即startWith;
            *               false表示，trie树中存储s，即contains
            * @return
            */
        public boolean search(String s, int start, boolean prefix) {
            //搜索到字符串末尾
            if(start == s.length()) {
                //startsWith情况直接返回true
                if(prefix) return true;
                //查找是否包含，需要检测终止位置
                if(children[26] != null) return true;
                return false;
            }
            char c = s.charAt(start);
            if(this.children[c - 'a'] == null) {
                return false;
            }
            return this.children[c - 'a'].search(s, start+1, prefix);
        }

    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
```