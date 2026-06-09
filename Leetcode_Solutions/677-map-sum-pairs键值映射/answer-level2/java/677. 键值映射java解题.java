### 解题思路
使用Trie进行解题，完成单词与值的映射关系

### 代码


```java
import java.util.TreeMap;

class MapSum {
    private class Node {
        // 每一个单词与一个值进行了映射
        public int value;
        public TreeMap<Character, Node> next;   // 下一节点是这个字符对引得一个映射

        public Node(int value) {
            this.value = value;
            next = new TreeMap<>();
        }

        public Node() {
            this(0);
        }
    }

    private Node root;
    /** Initialize your data structure here. */
    public MapSum() {
        root = new Node();
    }

    public void insert(String key, int val) {

        Node cur = root;
        for (int i = 0; i < key.length(); i ++){
            char c = key.charAt(i);
            if (cur.next.get(c) == null)
                cur.next.put(c, new Node());
            cur = cur.next.get(c);
        }
        cur.value = val;

    }

    public int sum(String prefix) {

        Node cur = root;

        for (int i = 0 ; i < prefix.length(); i ++){
            char c = prefix.charAt(i);
            if (cur.next.get(c) == null){
                return 0;
            }
            cur = cur.next.get(c);
        }
        return sum(cur);
    }

    private int sum(Node node){
        int res = node.value;
        for (char c : node.next.keySet()){
            res += sum(node.next.get(c));
        }

        return res;
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
```