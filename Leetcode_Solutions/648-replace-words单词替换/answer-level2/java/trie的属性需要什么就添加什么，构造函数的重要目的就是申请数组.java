### 解题思路
此处撰写解题思路
对于值不确定的不用在构造函数中初始化。
**搜索找到后，才替换，否则就是直接用原来的。**
`  可变字符串 StringBuilder`
String转换为字符数组。`word.toCharArray()`
### 代码

```java
class Solution {
    class TrieNode{
        String word;
        TrieNode[] children;
        TrieNode(){
            children =new TrieNode[26];
        }
    }
    public String replaceWords(List<String> roots, String sentence) {
        TrieNode trie = new TrieNode();
        for (String root: roots) {
            TrieNode cur = trie;
            for (char letter: root.toCharArray()) {
                if (cur.children[letter - 'a'] == null)
                    cur.children[letter - 'a'] = new TrieNode();
                cur = cur.children[letter - 'a'];
            }
            cur.word = root;
        }

        StringBuilder ans = new StringBuilder();

        for (String word: sentence.split("\\s+")) {
            if (ans.length() > 0)
                ans.append(" ");

            TrieNode cur = trie;
            for (char letter: word.toCharArray()) {
                if (cur.children[letter - 'a'] == null || cur.word != null)
                    break;
                cur = cur.children[letter - 'a'];
            }
            //trie在应用时，一定是建立在搜索的基础上。
            ans.append(cur.word != null ? cur.word : word);
        }
        return ans.toString();
    }
}

```