```
class Trie {
    //定义一个节点
    public class TrieNode{
        public int path;
        public int end;
        public TrieNode[] next;//以当前节点为前缀的数组
        //定义初始化类型
        public TrieNode(){
            path = 0;
            end = 0;
            next = new TrieNode[26]; //最多可以挂的数量，26个字母
        }
    }
    
    public TrieNode root;

    public Trie() {
        //初始化根节点
        root = new TrieNode();
    }
    
    /**
		 * 插入一个字符串的整个过程
		 * 1.将字符串变为字符数组
		 * 2.建立头结点
		 * 3.将数组中字符依次放入下一个位置
		 * 4.如果没有，建立新节点并放入，如果有就直接拿出来
		 * 5.将这个节点的路径数path +1，标记end
		 */
    public void insert(String word) {
        if(word == null) return;;
        char[] chars = word.toCharArray();
        TrieNode node = root;
        for (int i = 0; i < chars.length; i++) {
            int index = chars[i] - 'a';
            if(node.next[index] == null) {
                node.next[index] = new TrieNode();
            }
            node = node.next[index];
            node.path++;
        }
        node.end++;
    }
    
    /**
		 * 查找一个字符串的整个过程，返回该字符串插入次数
		 * 1.将字符串变为字符数组
		 * 2.建立头结点
		 * 3.将数组中字符依次放入下一个位置
		 * 4.如果没有，返回0；如果有就直接拿出来
		 * 5.返回标记end
         * 此题直接返回是否有结束标记
		 */
    public boolean search(String word) {
        if(word == null) return true;
        char[] chars = word.toCharArray();
        TrieNode node = root;
        for (int i = 0; i < chars.length; i++) {
            int index = chars[i] - 'a';
            if(node.next[index] == null) {
                return false;
            }
            node = node.next[index];

        }
        return node.end != 0;
    }
    
    /**
    * 返回以当前字符串为前缀的数量
    * 此题直接返回有或者没有
    */
    public boolean startsWith(String prefix) {
        if(prefix == null) return true;
        char[] chars = prefix.toCharArray();
        TrieNode node = root;
        for (int i = 0; i < chars.length; i++) {
            int index = chars[i] - 'a';
            if(node.next[index] == null) {
                return false;
            }
            node = node.next[index];

        }
        return node.path != 0;
    }
}

```
