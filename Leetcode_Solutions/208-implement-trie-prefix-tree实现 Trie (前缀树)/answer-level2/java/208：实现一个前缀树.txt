### leetcode208：实现一个前缀树
### 思路
- 前缀是也是一个树，结点包括两个属性，当前结点值value属性，下一个结点（这是一颗非二叉树，所以任意一个结点的子节点有26种可能，用Trie类型字符数组表示）。
   - 但是在search的时候还要判断当前结点是不是叶子结点，所以有第三个属性---判断是否是最后一个结点
   - 由于已知输入为全小写(a-z)的字母，所以可以使用一个长度为26的数组存储叶子节点。且由于a-z的ASCII码是连续的，其ASCII是从97-123，所以可以直接使用 ASCII码-97=对应节点的数组下标。
- insert（word）传入一个单词后构造前缀树的时候，将字符串word转化成字符数组进行遍历，要判断单词的当前字符是否在前缀树中，如果不在就要创建这个结点对象；如果存在就使用。将当前结点值变为孩子结点，所以要定义一个指针currentNode初始值是this。
- search（word）传入一个单词判断是否在前缀树中，将单词word转化为字符数组遍历，（需要对特殊情况的word进行判断）。如果当前字符存在于前缀树中就继续遍历下一个字符，如果不存在就让结果result=false。当遍历完当前字符数组的时候，还要判断此时currentNode指针指向的结点是否是叶子结点，如果是那么此时search的结果才是真正为true。
   - 假如有一个insert（popular），search（pop）的判断，前缀树中有一个popular的路径，此时r是叶子结点，p不是叶子结点，search（pop）结果应该是false，如果不进行叶子结点判断就是true了，与预期不符。
- startWith就简单的多了，与search类似，不过遍历完之后不再需要对尾结点进行判断。
```
class Trie {
    /**
     * 当前节点的值
     */
    public char value;
    /**
     * a-z有26个字母，需要访问时由于a的ASCII码为97，所以所有字母访问的对应下表皆为 字母的ASCII码-97
     */
    public Trie[] children=new Trie[26];
    /**
     * 标识此节点是否为某个单词的结束节点
     */
    public boolean endAsWord=false;
    
    public Trie() {
        
    }
    /**
     * 插入一个单词
     * @param word 单词
     */
    public void insert(String word) {
        if(word!=null){
            //分解成字符数组
            char[] charArr=word.toCharArray();
            //模拟指针操作,记录当前访问到的树的节点
            Trie currentNode=this;
            for(int i=0;i<charArr.length;i++){
                char currentChar=charArr[i];
                //根据字符获取对应的子节点
                Trie node=currentNode.children[currentChar-97];
                if(node!=null && node.value==currentChar){//判断节点是否存在
                   currentNode=node;
                }else{//不存在则创建一个新的叶子节点,并指向当前的叶子节点
                    node=new Trie();
                    node.value=currentChar;
                    currentNode.children[currentChar-97]=node;
                    currentNode=node;
                }
            }
            //这个标识很重要
            currentNode.endAsWord=true;
        }
    }
    /**
     * 检索指定单词是否在树中
     * @param word 单词
     */
    public boolean search(String word) {
        boolean result=true;
        if(word!=null && !word.trim().equals("")){
            char[] prefixChar=word.toCharArray();
            Trie currentNode=this;
            for(int i=0;i<prefixChar.length;i++){
                char currentChar=prefixChar[i];
                Trie node=currentNode.children[currentChar-97];
                if(node!=null && node.value==currentChar){//判断节点是否存在
                   currentNode=node;
                }else{
                    result=false;
                    break;
                }
            }
            if(result){
                result=currentNode.endAsWord;
            }
        }
        return result;
    }
    /**
     * 检索指定前缀是否在树中
     * @param word 单词
     */
    public boolean startsWith(String prefix) {
        boolean result=true;
        if(prefix!=null && !prefix.trim().equals("")){
            char[] prefixChar=prefix.toCharArray();
            Trie currentNode=this;
            for(int i=0;i<prefixChar.length;i++){
                char currentChar=prefixChar[i];
                Trie node=currentNode.children[currentChar-97];
                if(node!=null && node.value==currentChar){//判断节点是否存在
                    currentNode=node;
                }else{
                    result=false;
                    break;
                }
            }
        }
        return result;
    }
}
```