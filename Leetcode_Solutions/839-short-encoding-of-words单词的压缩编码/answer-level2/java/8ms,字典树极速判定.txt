### 解题思路
增速思路：1.手写快速排序，将字符数组按长度降序排列比用Arrays自带的排序要快很多
2.将每个字符串的字符逆序插入字典树，直接从字符串的尾部开始可以提高效率.
3.根结点作为成员变量可以省去传参所浪费的时间
### 代码

```java
public class Solution {
    Trie trie = new Trie();
    public int minimumLengthEncoding(String[] words) {
        int sum = 0 ;
        StringQuickSort(words);
        for ( String str  : words ) {
            sum += insert(str);
        }
        return sum;
    }

    public int insert(String str){
        boolean isnewword =false;
        TrieNode root = trie.root;
        for (int i = str.length()-1; i >=0 ; i--) {
            char c = str.charAt(i);
            int v = c - 'a' ;
            if (root.children[v] == null) {
                root.children[v] = new TrieNode(c);
                isnewword = true;
            }
                root = root.children[v];
        }
        return isnewword? str.length()+1:0;
    }

    public void StringQuickSort(String[] words){
        StringQuickSort(words,0,words.length-1);
    }

    public void StringQuickSort(String[] words,  int start ,int end ){
        if (end>start){
            int res =  partition(words,start,end);
            StringQuickSort(words,start,res-1);
            StringQuickSort(words,res+1,end);
        }
    }
    public int partition(String[] words,int start ,int end){
        int left = start , right = end +1 , v =words[start].length();
        while (true){
            while (--right>=start&&words[right].length()<v);
            while (++left<=end&&words[left].length()>v);
            if (right<=left){
                break;
            }
            String temp = words[left];
            words[left] = words[right];
            words[right] = temp;
        }
        String temp = words[start];
        words[start] = words[right];
        words[right] = temp ;
        return right;
    }
}
    class Trie {
    TrieNode root ;
    public Trie() {this.root =  new TrieNode();}
}
     class TrieNode {
    char val ;
    TrieNode[] children = new TrieNode[26];
    TrieNode(){}
    public TrieNode(char val) { this.val = val; }
}
```