### 解题思路
最近学了字典树(前缀树)，用字典树解题。
将所有的字符插入字典树，如果有共同前缀，证明每次遍历都只有一条路径
如果遍历到当前层超过了一个子节点不为空，或者当前不为空的节点是字符结束节点，就跳出遍历。

### 代码

```java
class Solution {
     /**
     * 最长公共前缀
     * 通过一个字典树来实现
     */
    public String longestCommonPrefix(String[] strs) {
        Trie14 trie14 = new Trie14();
        for (String str : strs) {
            if (str == null || str.length() == 0) {
                return "";
            }
            trie14.insert(str);
        }
        StringBuilder result = new StringBuilder();
        TrieNode14 node = trie14.root;
        while (node != null) {
            TrieNode14[] children = node.children;
            TrieNode14 charNode = null;
            String currentVar = "";
            for (TrieNode14 child : children) {
                if (child != null) {
                    charNode = child;
                    currentVar += charNode.var;
                }
            }
            //大于一个公共节点，结束
            if (currentVar.length() > 1) {
                break;
            }
            //到了结尾了，结束
            if (charNode == null) {
                break;
            }
            //更新当前节点
            node = charNode;
            result.append(currentVar);
            //如果当前单词遍历完了，结束，有：aa,a的情况
            if (node.isEnd) {
                break;
            }
        }
        return result.toString();
    }
}

class Trie14 {
    TrieNode14 root;

    Trie14() {
        this.root = new TrieNode14(' ');
    }

    public void insert(String word) {
        TrieNode14 current = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (current.children[c - 'a'] == null) {
                current.children[c - 'a'] = new TrieNode14(c);
            }
            current = current.children[c - 'a'];
        }
        current.isEnd = true;
    }

}

class TrieNode14 {
    char var;
    TrieNode14[] children = new TrieNode14[26];
    boolean isEnd;

    TrieNode14() {

    }

    TrieNode14(char var) {
        this.var = var;
    }
}
```