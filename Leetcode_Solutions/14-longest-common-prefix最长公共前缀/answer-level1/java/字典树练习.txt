
刚好最近学习了字典树这个数据结构，根据题意的最长公共前缀，感觉非常适合使用字典树来做
1.先把所有出现的单词加入到字典树中
2.从字典树头结点开始遍历，当遇到有一个节点拥有多个子节点或者当前节点的isword为true的时候返回结果。

```
class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuffer sb = new StringBuffer();
        if(strs.length == 0) return sb.toString();
        Trie trie = new Trie();
        for(String s: strs){
            if(s.equals(""))return s;
            insert(trie,s);
        }
     
        while(trie != null){
            int count = 0;
            char c = '0';
            for(int i=0;i<26;i++){
                if(trie.child[i]!=null){
                    count++;
                    c = (char)('a'+i);
                }
            }

            if(count == 1){
                sb.append(c);
                trie = trie.child[c-'a'];
                if(trie.isWord) break;
            }else{
                break;
            }
        }
  
        return sb.toString();
    }

    class Trie{
        boolean isWord;
        Trie[] child;

        public Trie(){
            isWord = false;
            child = new Trie[26];
        }
    }

      public void insert(Trie trie,String strs){
            Trie head = trie;
            for(int i=0;i<strs.length();i++){
                if(head.child[strs.charAt(i)-'a'] == null){
                    head.child[strs.charAt(i)-'a'] = new Trie();
                }
                head = head.child[strs.charAt(i)-'a'];
            }
            head.isWord = true;
    }

  

}
```
