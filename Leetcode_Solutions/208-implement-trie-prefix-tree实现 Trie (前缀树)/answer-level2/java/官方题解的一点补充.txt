关于字典树的实现官方题解已经给出了，但是题目好像有更新，按照官方的题解提交是错误的。我们以题目中给出的例子为例：

> Trie trie = new Trie();
> trie.insert("apple");
> trie.search("apple");   // 返回 true
> trie.search("app");     // 返回 false
> trie.startsWith("app"); // 返回 true
> trie.insert("app");   
> trie.search("app");     // 返回 true

使用官方题解的问题在于我们第一次`search("app")`的时候，返回的是`true`，所以我们需要在`search()`函数的循环中添加下面的代码判断`isEnd`属性值：

```java
    public boolean search(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            char currLetter = word.charAt(i);
            if (node.containsKey(currLetter)) {
                node = node.get(currLetter);
                // 判断当前是否遍历到了word的最后一个字母，并且isEnd 的值为false
                if (i +  1 == word.length() && node.isEnd() == false) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
```

修改完`search()`函数之后，我们的`startWith()`函数也需要修改（改成原来的`search()`就可以了）：

```java
    public boolean startsWith(String prefix) {
        TrieNode node = root;
        for (int i = 0; i < prefix.length(); i++) {
            char currLetter = prefix.charAt(i);
            if (node.containsKey(currLetter)) {
                node = node.get(currLetter);
            } else {
                return false;
            }
        }
        return true;
    }
```