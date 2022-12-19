### 解题思路
小白第一次写题解 多包涵
其实这题虽然写的是中等难度 但是做了一段时间的leetcode 有的简单难度比中等难多了……
其实就是根据甜姨（Sweetiee 🍬）的思路来的
早先学过trie树 但这题并没使我联想到trie树 看了题解才明白的

执行用时 :36 ms, 在所有 Java 提交中击败了47.37%的用户
内存消耗 :43 MB, 在所有 Java 提交中击败了16.66%的用户

有点low 但是新手多包涵

### 代码

```java
class Solution {
    //手撕trie树
    private class trieNode{
        //用map就可以不用数组了 避免开多余空间
        public TreeMap<Character,trieNode> next;
        trieNode(){
            next = new TreeMap<>();
        }
    }
    //有节点了自然就要开始创建trie树
    private class trieTree{
        //因为只需要一个add 所以trie树缩水成非常简单的东西 只有一个根节点
        public trieNode root = new trieNode();
        //开始写add
        public int add(String word){
            //类似指针的cur指向root根节点
            trieNode cur = root;
            //来一个flag 标注这是新单词
            Boolean isNew = false;
            //遍历要插入的单词 注意 是倒叙
            //注意要-1 否则直接越界
            for(int i = word.length()-1; i >=0; i--){
                //那charat来依次取出每个单词
                char c = word.charAt(i);
                //由于key值是character所以只需要get一下
                if(cur.next.get(c) == null){
                    //OK这里是新单词
                    isNew = true;
                    cur.next.put(c,new trieNode());
                }
                //无论是否存在 都需要走向下一个
                cur = cur.next.get(c);
            }
            // 如果是新单词的话编码长度增加新单词的长度+1 否则不变
            return isNew? word.length() + 1: 0;
        }
    }
    public int minimumLengthEncoding(String[] words) {
        int len = 0;
        trieTree trie = new trieTree();
        // 如果不排序 那么 em 和 emit 就会出问题
        //不排序的话先插入了em 那么emit也能插入 导致isNew的值不是我们想要的
        //words后面那一长串是lambda表达式
        Arrays.sort(words, (s1, s2) -> s2.length() - s1.length());
        // 单词插入trie 返回该单词增加的编码长度
        for (String word: words) {
            len += trie.add(word);
        }
        return len;
    }
}
```