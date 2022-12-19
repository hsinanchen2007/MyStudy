### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String replaceWords(List<String> dict, String sentence) {
        TrieNode trie = new TrieNode();
        for(String root:dict) {
            TrieNode.insert(root,trie);
        }
       
        StringBuffer ans = new StringBuffer();
        String[] words = sentence.split("\\s+");
        for(String word : words) {
            if (ans.length() > 0) {
                ans.append(" ");
            }
            TrieNode crawlNode = trie;
            for (char letter : word.toCharArray()) {
                int index = letter - 'a';
                if (Objects.isNull(crawlNode.children[index]) || Objects.nonNull(crawlNode.word)) {
                    break;
                }
                crawlNode = crawlNode.children[index];
                
            }
            ans.append(Objects.nonNull(crawlNode.word) ? crawlNode.word : word);
        }
        return ans.toString().trim();
    }
    static class TrieNode {
        private static final int ALPHABET_COUNT = 26;
        TrieNode[] children;
        String word;

        TrieNode() {
            children = new TrieNode[ALPHABET_COUNT];
        }

        /**
         * 从字典树中返回最后一个节点
         * @param input 输入字符串
         * @param trie 字典树
         * @return 落地TrieNode
         */
        static TrieNode insert(String input, TrieNode trie) {
            TrieNode crawlNode = trie;
            for (char letter : input.toCharArray()) {
                int index = letter - 'a';
                if (Objects.isNull(crawlNode.children[index])) {
                    crawlNode.children[index] = new TrieNode();
                }
                crawlNode = crawlNode.children[index];
            }
            crawlNode.word = input;
            return crawlNode;
        }
    }
}
```