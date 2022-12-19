### 解题思路
字典树的标准结构如下：

/**
 * trie树的一个例子是
 * see pain paint pair dog
 *
 *           [树根是空的]
 *          /    |     \
 *         d     p     s    // 字母顺序自然排序
 *         |     |     |
 *         o     a     e
 *         |     |     |
 *         g     i     e    // 'e' && 'g' --> isWholeWord = true
 *              / \
 *             n   r        // 'n' && 'r' --> isWholeWord = true
 *             |
 *             t            // 't' --> isWholeWord = true
 *
 *
 */

所以我们构建字典树也要根据上面的结构：
1. 需要一个子节点数组
2. 需要记录当前节点保存的一个字符c
3. 需要记录到当前节点是否是一个完整的单词
4. 需要经过当前节点的字母的数量（方便统计最大前缀）

请参考如下代码：

### 代码

```java
class Trie {

    protected int num;
    // 子节点
    protected Trie[] children;
    // 证明到这里为止是否是一个完整到单词，这个属性很重要
    protected boolean isWholeWord;
    // 当前节点的字符
    protected char nodeCharacter;
    // 是否有子节点
    protected boolean hasChild;

    // 构造函数用来初始化
    public Trie() {
        num = 1;
        // 26个英文字母
        children = new Trie[26];
        isWholeWord = false;
        hasChild = false;
    }

    // 插入一个单词
    public void insert(String word) {
        // 如果字符串为空就返回
        if (word == null || word.length() == 0) {
            return;
        }
        Trie node = this;
        char[] letters = word.toCharArray();
        for (int i = 0, len = word.length(); i < len; i++) {
            // 计算当前字母和a的偏移量
            int pos = letters[i] - 'a';
            // 如果某个子节点还没有字母
            if (node.children[pos] == null) {
                node.hasChild = true;
                node.children[pos] = new Trie();
                // 初始化计数就是1
                node.children[pos].nodeCharacter = letters[i];
            } else {
                node.children[pos].num++;
            }
            // 把当前节点变为父节点
            node = node.children[pos];
        }
        // 到最后的节点就是一个完整的单词
        node.isWholeWord = true;
    }

    // 搜索一个单词
    public boolean search(String word) {
        Trie node = this;
        for (int i = 0; i < prefix.length(); i++) {
            char c = prefix.charAt(i);
            node = node.children[c - 'a'];
            if (node == null) {
                return false;
            }
        }
        // 必须是完整的单词才可以
        if (node.isWholeWord) {
            return true;
        }
        return false;
    }

    // 是否包含这个前缀开头的词
    // 不需要是否是完整的单词
    public boolean startsWith(String prefix) {
        Trie node = this;
        for (int i = 0; i < prefix.length(); i++) {
            char c = prefix.charAt(i);
            node = node.children[c - 'a'];
            if (node == null) {
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