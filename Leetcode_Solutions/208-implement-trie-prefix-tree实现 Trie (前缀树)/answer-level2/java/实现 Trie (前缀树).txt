## 总结
本文面向中级用户。它介绍了以下内容：数据结构 Trie（前缀树）及其最常见的操作。

## 正文

#### 应用

Trie (发音为 "try") 或前缀树是一种树数据结构，用于检索字符串数据集中的键。这一高效的数据结构有多种应用：

##### 1. 自动补全

![无效的图片地址](https://pic.leetcode-cn.com/963cd3fc83e9618aba9cb78365c8a5bf6b7cef8967da0d204dede7844f6738f2-file_1562596867150){:width=400}
{:align=center}

*图 1. 谷歌的搜索建议*
{:align="center"}

##### 2. 拼写检查

![image.png](https://pic.leetcode-cn.com/4d18efbdd4d51ae3935b42cd59b11d66fb62f1586b9638f9499d2a18fa8919d0-image.png){:width=400}
{:align=center}

*图2. 文字处理软件中的拼写检查*
{:align="center"}

##### 3. IP 路由 (最长前缀匹配)

![无效的图片地址](https://pic.leetcode-cn.com/e3f22b3ab2df82e6c0a7880996749b5e62707e9ef925876e583d666343644526-file_1562596867150){:width=400}
{:align=center}

*图 3. 使用Trie树的最长前缀匹配算法，Internet 协议（IP）路由中利用转发表选择路径。*
{:align="center"}

##### 4. T9 (九宫格) 打字预测

![无效的图片地址](https://pic.leetcode-cn.com/00900cce532f199559249a47375a76b409f18876bc329087ac057fbe47085f5e-file_1562596867185){:width=200}
{:align=center}

*图 4. T9（九宫格输入），在 20 世纪 90 年代常用于手机输入*
{:align="center"}

##### 5. 单词游戏
![image.png](https://pic.leetcode-cn.com/e49e9f0b26566673c32bfbb7de404b5d563a0fe74070bb231de811a70e71f147-image.png){:width=300}
{:align=center}

*图 5. Trie 树可通过剪枝搜索空间来高效解决 Boggle 单词游戏*
{:align="center"}

还有其他的数据结构，如平衡树和哈希表，使我们能够在字符串数据集中搜索单词。为什么我们还需要 Trie 树呢？尽管哈希表可以在 $O(1)$ 时间内寻找键值，却无法高效的完成以下操作：

* 找到具有同一前缀的全部键值。
* 按词典序枚举字符串的数据集。

Trie 树优于哈希表的另一个理由是，随着哈希表大小增加，会出现大量的冲突，时间复杂度可能增加到 $O(n)$，其中 $n$ 是插入的键的数量。与哈希表相比，Trie 树在存储多个具有相同前缀的键时可以使用较少的空间。此时 Trie 树只需要 $O(m)$ 的时间复杂度，其中 $m$ 为键长。而在平衡树中查找键值需要 $O(m \log n)$ 时间复杂度。

#### Trie 树的结点结构

Trie 树是一个有根的树，其结点具有以下字段：。

* 最多 $R$ 个指向子结点的链接，其中每个链接对应字母表数据集中的一个字母。
本文中假定 $R$ 为 26，小写拉丁字母的数量。
* 布尔字段，以指定节点是对应键的结尾还是只是键前缀。

![无效的图片地址](https://pic.leetcode-cn.com/3463d9e7cb323911aa67cbd94910a34d88c9402a1ab41bbea10852cd0a74f2af-file_1562596867185){:width=400}
{:align=center}

*图 6. 单词 "leet" 在 Trie 树中的表示*
{:align="center"}

```Java [solution 1]
class TrieNode {

    // R links to node children
    private TrieNode[] links;

    private final int R = 26;

    private boolean isEnd;

    public TrieNode() {
        links = new TrieNode[R];
    }

    public boolean containsKey(char ch) {
        return links[ch -'a'] != null;
    }
    public TrieNode get(char ch) {
        return links[ch -'a'];
    }
    public void put(char ch, TrieNode node) {
        links[ch -'a'] = node;
    }
    public void setEnd() {
        isEnd = true;
    }
    public boolean isEnd() {
        return isEnd;
    }
}
```
Trie 树中最常见的两个操作是键的插入和查找。

#### 向 Trie 树中插入键

我们通过搜索 Trie 树来插入一个键。我们从根开始搜索它对应于第一个键字符的链接。有两种情况：

* 链接存在。沿着链接移动到树的下一个子层。算法继续搜索下一个键字符。
* 链接不存在。创建一个新的节点，并将它与父节点的链接相连，该链接与当前的键字符相匹配。

重复以上步骤，直到到达键的最后一个字符，然后将当前节点标记为结束节点，算法完成。

![无效的图片地址](https://pic.leetcode-cn.com/0cddad836ee9a200b150a3d89f96035f44f3643c4fba0cb1f329e2307c714895-file_1562596867185)

*图 7. 向 Trie 树中插入键*
{:align="center"}

```Java [solution 2]
class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void insert(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            char currentChar = word.charAt(i);
            if (!node.containsKey(currentChar)) {
                node.put(currentChar, new TrieNode());
            }
            node = node.get(currentChar);
        }
        node.setEnd();
    }
}
```
 
**复杂度分析**
* 时间复杂度：$O(m)$，其中 $m$ 为键长。在算法的每次迭代中，我们要么检查要么创建一个节点，直到到达键尾。只需要 $m$ 次操作。

* 空间复杂度：$O(m)$。最坏的情况下，新插入的键和 Trie 树中已有的键没有公共前缀。此时需要添加 $m$ 个结点，使用 $O(m)$ 空间。

#### 在 Trie 树中查找键
每个键在 trie 中表示为从根到内部节点或叶的路径。我们用第一个键字符从根开始，。检查当前节点中与键字符对应的链接。有两种情况：
* 存在链接。我们移动到该链接后面路径中的下一个节点，并继续搜索下一个键字符。
* 不存在链接。若已无键字符，且当前结点标记为 `isEnd`，则返回 true。否则有两种可能，均返回 false :
    * 还有键字符剩余，但无法跟随 Trie 树的键路径，找不到键。
    * 没有键字符剩余，但当前结点没有标记为 `isEnd`。也就是说，待查找键只是Trie树中另一个键的前缀。

![image.png](https://pic.leetcode-cn.com/ba775065813363474d982b509ae99aa5423418a3ee7e5aa71f9aa4d062b6e19e-image.png){:width=400}
{:align=center}

*图 8. 在 Trie 树中查找键*
{:align="center"}

```Java [solution 3]
class Trie {
    ...

    // search a prefix or whole key in trie and
    // returns the node where search ends
    private TrieNode searchPrefix(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
           char curLetter = word.charAt(i);
           if (node.containsKey(curLetter)) {
               node = node.get(curLetter);
           } else {
               return null;
           }
        }
        return node;
    }

    // Returns if the word is in the trie.
    public boolean search(String word) {
       TrieNode node = searchPrefix(word);
       return node != null && node.isEnd();
    }
}
```

**复杂度分析**

* 时间复杂度 : $O(m)$。算法的每一步均搜索下一个键字符。最坏的情况下需要 $m$ 次操作。
* 空间复杂度 : $O(1)$。

#### 查找 Trie 树中的键前缀

该方法与在 Trie 树中搜索键时使用的方法非常相似。我们从根遍历 Trie 树，直到键前缀中没有字符，或者无法用当前的键字符继续 Trie 中的路径。与上面提到的“搜索键”算法唯一的区别是，到达键前缀的末尾时，总是返回 true。我们不需要考虑当前 Trie 节点是否用 “isend” 标记，因为我们搜索的是键的前缀，而不是整个键。


![image.png](https://pic.leetcode-cn.com/7cc64e93088feeedece697a7cae0c7240245e4c5e05de22634b610d7dddb31c8-image.png){:width=400}
{:align=center}

*图 9. 查找 Trie 树中的键前缀*
{:align="center"}

```Java [solution 4]
class Trie {
    ...

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
        TrieNode node = searchPrefix(prefix);
        return node != null;
    }
}
```

**复杂度分析**

* 时间复杂度 : $O(m)$。
* 空间复杂度 : $O(1)$。

## 练习题目

下面是一些很好的问题，供您练习使用 Trie 数据结构。

1. [添加与搜索单词](https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/) - 一个 Trie 树的直接应用。
2. [单词搜索 II](https://leetcode-cn.com/problems/word-search-ii/) - 类似 Boggle 的游戏。

