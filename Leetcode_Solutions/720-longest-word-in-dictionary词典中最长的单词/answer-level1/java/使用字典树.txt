**字典树典型应用**
1. 首先构造一棵 trie 树
```
public class Trie{
    boolean isTrie;
    int len;
    public Trie[] tries = new Trie[26];
    public Trie(){
        isTrie = false;
    }
    public void insert(String str, Trie trie){
        if(str.length() == 0){
            return;
        }
        int i = 0;
        while(i < str.length()){
            if(trie.tries[str.charAt(i) - 'a'] == null){
                trie.tries[str.charAt(i) - 'a'] = new Trie();
            }
            trie = trie.tries[str.charAt(i) - 'a'];
            i ++;
        }
        trie.isTrie = true;
        trie.len = i;
    }
}
```

2. 对字典树进行搜索，求最长的字符串
```
class Solution {
    String str = "";
    public String longestWord(String[] words) {
        Trie trie = new Trie();
        for(int i = 0 ; i < words.length ; i ++){
            trie.insert(words[i],trie);
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0 ; i < 26 ; i ++){
            if(trie.tries[i] != null){
                sb.append((char)(i + 97));
                getLongestString(trie.tries[i], sb);
                sb.deleteCharAt(sb.length() - 1);
            }
        }
        return str;
    }
    public void getLongestString(Trie trie, StringBuilder sb){
        if(!trie.isTrie) return;
        if(sb.length() > str.length()){
            str = sb.toString();
        }
        for(int i = 0 ; i < 26 ; i ++){
            if(trie.tries[i] != null){
                sb.append((char)(i + 97));
                getLongestString(trie.tries[i], sb);
                sb.deleteCharAt(sb.length() - 1);
            }
        }
    }
}
```

