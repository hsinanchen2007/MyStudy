### 解题思路
1. 看了大多数的实现都是每个节点需要一个 26 字母的数组，会造成比较多的内存消耗
2. 这里直接使用 hashMap 作为链式结构，只存储出现过得单词

### 代码

```java
class Trie {

    class TireNode {
        boolean wordEnd;   
        public HashMap<Character, TireNode> hashMap;
        TireNode() {
            hashMap = new HashMap<>();
            wordEnd = false;
        }
    }

    TireNode tireNode; 

    /** Initialize your data structure here. */
    public Trie() {
        tireNode = new TireNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TireNode pNode = tireNode;
        for (int i = 0; i < word.length(); i++) {
            TireNode tmpNode = pNode.hashMap.get(word.charAt(i));
            if (tmpNode == null) {
                tmpNode = new TireNode();
                pNode.hashMap.put(word.charAt(i), tmpNode);
            }
            if (i == word.length() - 1) {
                tmpNode.wordEnd = true;
            }
            pNode = tmpNode;
        }
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TireNode tmpNode = tireNode; 
        for (int i = 0; i < word.length(); i++) {
            tmpNode = tmpNode.hashMap.get(word.charAt(i));
            if (tmpNode == null) {
                return false;
            }
        }
        
        if (tmpNode != null && tmpNode.wordEnd) {
            return true;
        }

        return false; 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TireNode tmpNode = tireNode; 
        for (int i = 0; i < prefix.length(); i++) {
            tmpNode = tmpNode.hashMap.get(prefix.charAt(i));
            if (tmpNode == null) {
                return false;
            }
        }

        return true; 
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