### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    //普通方式
    public int minimumLengthEncoding(String[] words) {
        //首先让数组中元素按照长度倒排
       Arrays.sort(words,(a,b)->b.length()-a.length());
       String sb="";
       for(String str:words){
           //如果不排序比如判断me,在判断time,结果会有问题会多计算,所以保证数组的长度从大到小
           if(!sb.contains(str+"#")){
               sb=sb+str+"#";
           }
       }
       return sb.length();
    }
}
```
```java
//字典树
class Solution {
    public int minimumLengthEncoding(String[] words){
        int len=0;
        //排序
        Arrays.sort(words,(a,b)->b.length()-a.length());
        Trie trie=new Trie();
        for(String str:words){
            len=len+trie.insert(str);
        }
        return len;
    }
    class Trie{
        private TrieNode trieNode=new TrieNode();

        public int insert(String str){
            TrieNode[] trieRoot=trieNode.trieRoot;
            boolean isNew=false;
            //倒着插入,因为是判断后缀
            for(int i=str.length()-1;i>=0;i--){
                char c=str.charAt(i);
                if(trieRoot[c-'a']==null){
                    isNew=true;
                    trieRoot[c-'a']=new TrieNode();
                }
                trieRoot = trieRoot[c - 'a'].trieRoot;
            }
            return isNew?str.length()+1:0;
        }
    }
    class TrieNode{
        TrieNode[] trieRoot=new TrieNode[26];
    }
}
```