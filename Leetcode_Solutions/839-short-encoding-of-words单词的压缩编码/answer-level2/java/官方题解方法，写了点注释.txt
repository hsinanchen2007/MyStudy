### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        TrieNode root = new TrieNode();
        
        //保存每个word的头部对应的node方便判断是否应该加上这个word的长度，
        //否则需要遍历整颗树,对node计数
        //以node为键，防止重复的字符串计算多次。
        Map<TrieNode,Integer> map = new HashMap<>();  
       
        for(int i=0;i<words.length;i++){
            String word=words[i];
            TrieNode cur = root;
            for(int j=word.length()-1;j>=0;j--){
                cur=cur.get(word.charAt(j));
            }
            map.put(cur,i);
        }
        int ans=0;
        for(TrieNode node:map.keySet()){
            if(node.count == 0){
                ans+=words[map.get(node)].length()+1;
            }
        }
        return ans;

    }
    public class TrieNode{
        TrieNode[] children;//相当于二叉树里面的left,right指针。
        int count=0;
        public TrieNode(){
            children=new TrieNode[26];
        } 
        public TrieNode get(char a){
            if(children[a-'a'] == null){
                children[a-'a'] = new TrieNode();
                count++;
            }
            return children[a-'a'];    
        }
    }
}
```