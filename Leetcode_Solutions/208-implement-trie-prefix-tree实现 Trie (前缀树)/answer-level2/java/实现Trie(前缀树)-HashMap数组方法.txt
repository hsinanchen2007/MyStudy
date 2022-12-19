### 解题思路
1. 首先先理解前缀树的思想，主要是将字符串的每一个字符保存到树的结点中。然后通过树的父子关系，将字符串串起来。
2. 然后要保存每个结点的状态，其中包括该节点的子结点是哪些，该节点是否为终止节点。并且每个结点都应有一个标识符。
3. 在本题中，采用了HashMap数组来存储所有点的信息，首先申请了100000长度的数组，然后每个值都可以初始化为HashMap。color数组保存了每一个点是否为终止节点。变量k代表每个节点的标识。
4. 首先在insert方法中，将String转化为char数组，加快遍历速度。然后从节点0开始遍历，判断当前节点的边中是否包含当前字符，如果包含，则将点变为Hashmap中字符对应的点。否则将(当前字符，k)插入当前节点的hashMap中，k++。遍历结束后，color数组对应的最后一个点赋为1，代表其为终止节点。
5. 在search方法中，同样地方法遍历，当最后一个点为终止节点，返回true，否则为false。
6. 在startsWith方法中同理，只要遍历中有字符不在当前节点的key中，则为false。

1. 更好的方法是构造一个节点类，然后通过节点扩展节点的方式解决问题，如第二种方法，思想和第一种一样，但是代码思路更简洁，且复杂度更低。

### 代码

```java
class Trie {
    private HashMap<Character, Integer>[] map;
    private int k;
    private int[] color;
    private final int MAX_WORDS = 100000;
    /** Initialize your data structure here. */
    public Trie() {
        map = new HashMap[MAX_WORDS];
        for(int i = 0; i < MAX_WORDS; i++)
            map[i] = new HashMap<>();
        k = 1;
        color = new int[MAX_WORDS];
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        int p = 0;
        for(Character c : word.toCharArray()){
            if(!map[p].containsKey(c)){
                map[p].put(c, k);
                k++;
            }
            p = map[p].get(c);
        }
        color[p] = 1;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        int p = 0;
        for(Character c : word.toCharArray()){
            if(!map[p].containsKey(c)) return false;
            p = map[p].get(c);
        }
        return color[p] == 1;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        int p = 0;
        for(Character c : prefix.toCharArray()){
            if(!map[p].containsKey(c)) return false;
            p = map[p].get(c);
        }
        return true;
    }
}

### 代码

class Trie {

    public class TrieNode{
        boolean flag = false;
        HashMap<Character, TrieNode> hashmap = new HashMap<>();

        public void setEnd(){
            flag = true;
        }
    }

    private TrieNode root;

    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode t = root;
        for(Character c : word.toCharArray()){
            if(!t.hashmap.containsKey(c)){
                TrieNode next = new TrieNode();
                t.hashmap.put(c, next);
            }
            t = t.hashmap.get(c);
        }
        t.setEnd();
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode t = root;
        for(Character c : word.toCharArray()){
            if(!t.hashmap.containsKey(c)) return false;
            t = t.hashmap.get(c);
        }
        return t.flag;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode t = root;
        for(Character c : prefix.toCharArray()){
            if(!t.hashmap.containsKey(c)) return false;
            t = t.hashmap.get(c);
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