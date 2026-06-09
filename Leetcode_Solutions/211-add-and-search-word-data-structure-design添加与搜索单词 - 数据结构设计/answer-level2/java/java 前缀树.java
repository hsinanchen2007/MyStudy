```
class TrieNode {
    private int count;
    private int prefixCount;
    TrieNode[] nextNode = new TrieNode[26];

    public TrieNode() {
        count = 0;
        prefixCount = 0;
    }

    public void insert(TrieNode root, String word) {
        if (root == null || word == null || word.length() == 0) {
            return;
        }
        for (char c : word.toCharArray()) {
            if (root.nextNode[c - 'a'] == null) {
                root.nextNode[c - 'a'] = new TrieNode();
            }
            root = root.nextNode[c - 'a'];
            root.prefixCount++;
        }
        root.count++;
    }

    public int search(TrieNode root, String word) {
        if (root == null || word == null || word.length() == 0) {
            return -1;
        }
        char[] charArray = word.toCharArray();
        for (int j = 0; j < charArray.length; j++) {
            if (charArray[j] != '.' && root.nextNode[charArray[j] - 'a'] == null) {
                return -1;
            } else if (charArray[j] == '.') {
                int result = 0;
                for (int i = 0; i < 26; i++) {
                    if (j == charArray.length - 1) {
                        if (root.nextNode[i] != null && root.nextNode[i].count != 0) {
                            result += root.nextNode[i].count;
                        }
                    } else {
                       int r = search(root.nextNode[i], word.substring(j + 1));
                       if(r > 0) {
                           result += r;
                       }
                    }
                }
                if(result > 0) {
                    return result;
                }
                return -1;
            }
            root = root.nextNode[charArray[j] - 'a'];
        }
        if (root.count == 0) {
            return -1;
        }
        return root.count;
    }

    public int searchPrefix(TrieNode root, String prefix) {
        if (root == null || prefix == null || prefix.length() == 0) {
            return -1;
        }
        for (char c : prefix.toCharArray()) {
            if (root.nextNode[c - 'a'] == null) {
                return -1;
            }
            root = nextNode[c - 'a'];
        }
        return root.prefixCount;
    }

}

class WordDictionary {
    private TrieNode trieNode;

    /** Initialize your data structure here. */
    public WordDictionary() {
        trieNode = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        trieNode.insert(trieNode, word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return trieNode.search(trieNode, word) != -1;
    }
}
```
