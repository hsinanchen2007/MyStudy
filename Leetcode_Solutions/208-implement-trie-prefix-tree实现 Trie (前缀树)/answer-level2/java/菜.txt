### 解题思路
难点在于search时判断trie小word长,trie长word小,子节点是否符合当前word中的字符,与trie长word小的情况下,判断遍历完word后的当前trie节点是否是一个单词的最后一个字符(即判断isWord)这几种情况

### 代码

```java
class Trie {

//根节点不存值
    TrieNode root;

    /**
     * Initialize your data structure here.
     */
    public Trie()
    {
        root = new TrieNode();

    }

    /**
     * Inserts a word into the trie.
     */
    public void insert(String word)
    {
        int i = 0;
        TrieNode currentNode = root;
        while (i != word.length())
        {
            //查看子节点是否有符合的字符
            if (currentNode.childNode.get(word.charAt(i)) != null)
            {
                currentNode = currentNode.childNode.get(word.charAt(i));
                i++;
                continue;
            }

            //构造新节点
            TrieNode newNode = new TrieNode();
            currentNode.childNode.put(word.charAt(i), newNode);
            currentNode = newNode;
            i++;

        }

        currentNode.isWord=true;

    }

    /**
     * Returns if the word is in the trie.
     */
    /**
     * 与startWith()不同点是,需要遍历完word之后且是到达指定的为word节点
     *
     * @param word
     * @return
     */
    public boolean search(String word)
    {
        int i = 0;
        TrieNode currentNode = root;
        //如果没到达前缀树的叶节点
        while (!currentNode.childNode.isEmpty())
        {
            //判断遍历完了word但没到达叶节点这种情况,即word小树长
            if (i != word.length())
            {
                //查看子节点是否有符合的字符
                if (currentNode.childNode.get(word.charAt(i)) != null)
                {
                    currentNode = currentNode.childNode.get(word.charAt(i));
                    i++;
                    continue;
                }
                return false;
            }
            return currentNode.isWord;

        }
        //判断是否到达了叶节点但没遍历完word,即word长树小的情况
        return i == word.length();
    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String prefix)
    {
        int i = 0;
        TrieNode currentNode = root;
        while (i != prefix.length())
        {
            //查看子节点是否有符合的字符,如果没有或已经到达了叶节点则返回false
            if (currentNode.childNode.get(prefix.charAt(i)) != null)
            {
                currentNode = currentNode.childNode.get(prefix.charAt(i));
                i++;

            } else
            {
                return false;
            }
        }
        return true;
    }
}
class TrieNode
{
    //子节点
    Map<Character, TrieNode> childNode = new HashMap<>();

    boolean isWord;
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
```