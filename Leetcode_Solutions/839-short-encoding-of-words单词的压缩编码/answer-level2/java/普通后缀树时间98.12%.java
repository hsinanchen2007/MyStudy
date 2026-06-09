### 解题思路
        //只有某个单词是另一个的后缀的时候才行啊，如果能是别人的后缀就直接把这个单词删除就可以了
        //先排序，单词长的在前边，先插长的，如果插入过程中产生了新的树，这个单词就不是任何单词的后缀，所以结果就直接加上word.length()+1就可以了.
//后缀树结构看定义，对外提供1个接口，往树中插入一个单词。
### 代码

```java

class TrieNode {
    private TrieNode[] children;
    TrieNode() {
        children = new TrieNode[26];
    }
    private boolean insert(char c) {
        if (children[c - 'a'] == null) {
            children[c - 'a'] = new TrieNode();
            return true;
        }
        return false;
    }
    public boolean insert(String s) {
        TrieNode cur=this;
        boolean createnew =false;
        char nowc;
        for(int i=s.length()-1;i>=0;i--){
            nowc=s.charAt(i);
            createnew=cur.insert(nowc);
            cur=cur.children[nowc-'a'];
        }
        return createnew;
    }
}
class Solution {
    public int minimumLengthEncoding(String[] words) {
        //只有某个单词是另一个的后缀的时候才行啊，如果能是别人的后缀就直接把这个单词删除就可以了
        Arrays.sort(words,(String a,String b)->{
            return b.length()-a.length();
        });
        boolean createnew=false;
        TrieNode root=new TrieNode();
        int sum=0;
        for(String word:words){
            createnew=root.insert(word);
            if(createnew)sum+=word.length()+1;
        }
        return sum;
    }
}


```