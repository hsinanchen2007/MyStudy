### 解题思路
关键在于后缀
将每个word倒序插入Trie前缀树中

明明看了官方代码，自己写的时候还是踩了很多坑。。
用一个HashMap来存储每个(TrieNode,i),因为后续还要用TrieNode.count==0来判断是否是叶结点，然后再由i找出words[i]的长度。


### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        //关键在于后缀
        //将每个word倒序插入Trie前缀树中
        TrieNode head=new TrieNode();
        HashMap<TrieNode,Integer> map=new HashMap<>();
        for(int k=0;k<words.length;k++){
            TrieNode current=head;
            for(int i=words[k].length()-1;i>=0;i--){
                char c=words[k].charAt(i);
                current=current.get(c);
            }
            map.put(current,k);
        }
        int ans=0;
        for(TrieNode e:map.keySet()){
            if(e.count==0){
            ans=ans+words[map.get(e)].length()+1;
            }
        }
        return ans;
    }
    public class TrieNode{
        private TrieNode[] links;
        private int count;
        public TrieNode(){
            links=new TrieNode[26];
            count=0;
        }
        public TrieNode get(char c){
            int a=c-'a';
            if(links[a]==null){
                links[a]=new TrieNode();
                count++;
            }
            return links[a];
        }

    }
}
```