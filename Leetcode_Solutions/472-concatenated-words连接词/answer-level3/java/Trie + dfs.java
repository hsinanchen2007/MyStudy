1.先把trie给写好
2.将words建成trie
3.循环words对它进行dfs
4.循环 如果找到一个Node是isWord的时候 进行dfs 传入的参数count+1
5.最后判断是否count > 0 并且满足isWord为true
```java []
class Solution {
    class TrieNode{
        TrieNode[] children = new TrieNode[26];
        boolean isWord = false;
    }
    
    TrieNode node = new TrieNode();
    public void insert(String s) {
        TrieNode cur = node;
        for(int i = 0; i < s.length(); i++)
        {
            int pos = s.charAt(i) - 'a';
            if(cur.children[pos] == null)
                cur.children[pos] = new TrieNode();
            cur = cur.children[pos];
        }
        cur.isWord = true;
    }
    
    List<String> res = new ArrayList<>();
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        if(words.length == 0)
            return res;
        
        for(String word: words)
        {
            if(word.length() != 0)
                insert(word);
        }
        
        for(String word: words)
        {
            if(dfs(word, node, 0, 0))
                res.add(word);
        }
        return res;
    }
    
    public boolean dfs(String word, TrieNode cur, int count, int index) {
        for(int i = index; i < word.length(); i++)
        {
            int pos = word.charAt(i) - 'a';
            if(cur.children[pos] == null)
                return false;
            cur = cur.children[pos];
            if(cur.isWord && dfs(word, node, count + 1, i + 1))
                return true;
        }
        return count > 0 && cur.isWord;
    }
}
```