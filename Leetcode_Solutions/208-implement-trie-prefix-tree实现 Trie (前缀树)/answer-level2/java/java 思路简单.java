### 解题思路
主要理解trie的结构，trie是一个树，其每个节点的孩子节点是一个长度为26的数组，每个节点表示一个字母，有一个是否是单词结尾的标识。

insert过程就是将单词每一位加入树中，并在最后一位的节点处将is_word的标识设为true。
search和searchwith的过程基本相同，search需要多判断一步是否是单词结尾

### 代码

```java
class Trie {

    class Treenode{
        public boolean is_word;//判断是否是单词的结尾
        public Treenode[] children;
        Treenode(){
            is_word=false;
            children=new Treenode[26];//每个节点存26个孩子节点
        }
    }
    /** Initialize your data structure here. */
    private Treenode root;
    public Trie() {
        this.root = new Treenode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        Treenode p = root;
        for(int i=0;i<word.length();i++ ){
            int index = word.charAt(i)-'a';
            if(p.children[index]==null)//不存在才创建，开始忘了这个，一直报错
            p.children[index] = new Treenode();//在第index位上创建孩子节点
            p = p.children[index];//p往下走
        }
        p.is_word = true;//在最后一位上加上结束标记
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Treenode temp = root;
        for(int i=0;i<word.length();i++ )
        {
            int index = word.charAt(i)-'a';
            if(temp.children[index]!=null)//如果非空，继续往下，空则返回false
            {
                temp=temp.children[index];
                continue;
            }
            else return false;
        }
        if(temp.is_word==true)
         return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Treenode temp = root;
        return find(prefix,temp);
    }
    private boolean find(String word, Treenode temp)
    {
        for(int i=0;i<word.length();i++ )
        {
            int index = word.charAt(i)-'a';
            if(temp.children[index]!=null)//如果非空，继续往下，空则返回false
            {
                temp=temp.children[index];
                continue;
            }
            else return false;
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
```