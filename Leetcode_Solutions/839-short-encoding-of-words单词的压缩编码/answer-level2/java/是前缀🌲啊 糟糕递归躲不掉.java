### 解题思路
分两步：
- 第一步，做一个字典树Trie，把单词列表中的每个单词倒序（从单词最后一个字母从后向前）插入Trie中
- 第二步，递归遍历字典树，求和每个叶子结点的深度

### 代码

```java
class Solution {
    int sum;

    public int minimumLengthEncoding(String[] words) {
        TrieNode root = new TrieNode();
        for(String word : words) {
            root.insert(word.toCharArray());
        }
        sum = 0;
        calDepth(root, 1);
        return sum;
    }

    public void calDepth(TrieNode node, int depth) {
        boolean noChild = true;
        for(TrieNode child : node.children) {
            if(child != null) {
                calDepth(child, depth + 1);
                noChild = false;
            }
        }
        if(noChild) {
            sum += depth;
        }
    }
}

class TrieNode {
    TrieNode[] children;

    TrieNode() {
        children = new TrieNode[26];
    }
    
    public void insert(char[] word){
        TrieNode node = this;
        for(int i=word.length-1; i>=0; i--) {
            char c = word[i];
            if(node.children[c-'a'] == null) {
                node.children[c-'a'] = new TrieNode();
            }
            node = node.children[c-'a'];
        }
    }
}
```