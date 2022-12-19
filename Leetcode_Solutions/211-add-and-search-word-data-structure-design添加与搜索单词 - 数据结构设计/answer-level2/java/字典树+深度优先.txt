### 解题思路
此处撰写解题思路

### 代码

```java
class WordDictionary {
    TrieNode trieNode=new TrieNode();

    public WordDictionary(){
        
    }

    // 添加单词
    public void addWord(String word){
        TrieNode[]root=trieNode.node;
        for(int i=0;i<word.length();i++){
            if(root[word.charAt(i)-'a']==null){
                root[word.charAt(i)-'a']=new TrieNode();
            }
            TrieNode temp=root[word.charAt(i)-'a'];
            //如果是结尾将isEnd改为true
            if(i==word.length()-1){
                temp.isEnd=true;
                root[word.charAt(i)-'a']=temp;
            }
            root=temp.node;
        }
    }

    public boolean search(String word){
       return search(trieNode,word,0);
    }

    public boolean search(TrieNode root,String word,int index){
        //如果到达结尾,判断最后一个字母是否是节点单词
        if(index==word.length()){
            return root.isEnd;
        }
        if(word.charAt(index)=='.'){
            for(TrieNode trieNode:root.node){
                //如果是'.'遍历循环所有的节点是否找到满足.后面的元素
                if(trieNode!=null&&search(trieNode,word,index+1)){
                    return true;
                }
            }
            return false;
        }else{
            //如果不存在该字符说明字典树中不存在元素,直接返回false
            if(root.node[word.charAt(index)-'a']==null){
                return false;
            }
            return search(root.node[word.charAt(index)-'a'],word,index+1);
        }
    }
    class TrieNode{
        //定义是否是结尾
        boolean isEnd=false;
        //定义数组
        TrieNode[]node=new TrieNode[26];
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
```