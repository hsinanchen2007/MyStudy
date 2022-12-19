### 解题思路
**思路**：根据已添加单词确定下一个单词的前缀，再搜索。

比如已经添加了两个单词 $ball$ 和 $area$，要添加下一个单词，我们首先要获取下一个单词的前缀，第一个字母是第一个单词的第三个位置$（l）$，第二个字母是第二个单词的第三个位置 $(e)$，这样就构成了前缀 $le$，然后添加 $lead$...也就是说，我们遍历前面的添加过的单词的第 $row$ 个位置（$row$是新来的单词应该放在第几行，或者说是$list.size()$，我们这个列表里放了几个了放了两个就是要找下标为 $2$ 的列）

搜索前缀很快就想到了用 $Trie$，一开始我的TrieNode的设计错误，不是查 $trie$ 树中有没有这样的前缀，而是查有哪些单词包含了这样的前缀，查出这些单词再搜索
 
在 $TrieNode$ 类中，添加了一个 $List$ 来存储所有以该前缀开头的单词。也就是在任何节点上，我们都知道单词列表中所有具有该节点前缀的单词。可以搜索所有可能的组合。

$ps$：这个单词是可以重复使用的...
### 代码

```java
class Solution {
    public List<List<String>> wordSquares(String[] words) {
        List<List<String>> res = new ArrayList<>();
        if (words == null || words.length == 0) {
            return res;
        }
        // 遍历每一个单词作为起点
        Trie trie = new Trie(words);
        List<String> list = new ArrayList<>();
        for (String word : words) {
            list.add(word);
            dfs(words, trie, list, res);
            list.remove(list.size() - 1);
        }
        return res;

    }
    // 
    private void dfs(String[] words, Trie trie, List<String> list, List<List<String>> res) {
        if (list.size() == words[0].length()) {
            res.add(new ArrayList<>(list));
            return;
        }
        // 获取list.size()这一列的前缀
        int idx = list.size();
        StringBuilder sb = new StringBuilder();
        for (String word : list) {
            sb.append(word.charAt(idx));
        }
        String prefix = sb.toString();
        List<String> temp = trie.search(prefix);
        for (String word : temp) {
            list.add(word);
            dfs(words, trie, list, res);
            list.remove(list.size() - 1);
        }
    }
}
class TrieNode{
    public TrieNode[] children;
    // 用于存放包含该前缀的word
    public List<String> list;

    public TrieNode() {
        children = new TrieNode[26];
        list = new ArrayList<>();
    }
}

class Trie{
    private TrieNode root;

    public Trie(String[] words) {
        root = new TrieNode();
        insert(words);
    }

    public void insert(String[] words) {
        for (String word : words) {
            TrieNode cur = root;
            char[] sc = word.toCharArray();
            for (int i = 0; i < sc.length; i++) {
                int idx = sc[i] - 'a';
                if (cur.children[idx] == null) {
                    cur.children[idx] = new TrieNode();
                }
                cur = cur.children[idx];
                cur.list.add(word);
            }
        }
    }

    // 查找以该单词开头的所有word
    public List<String> search(String prefix) {
        TrieNode cur = root;
        char[] sc = prefix.toCharArray();
        for (int i = 0; i < sc.length; i++) {
            int idx = sc[i] - 'a';
            if (cur.children[idx] == null) {
                return new ArrayList<>();
            }
            cur = cur.children[idx];
        }
        return cur.list;
    }
}
```