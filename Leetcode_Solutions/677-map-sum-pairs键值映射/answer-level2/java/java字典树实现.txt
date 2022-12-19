```
class MapSum {

    private Node root;

    public MapSum() {
        root = new Node();
    }

    public void insert(String key, int val) {
        Node cur = root;
        for (int i = 0; i < key.length(); i++) {
            char c = key.charAt(i);
            // 判断当前子节点中是否有字符 c
            if (! cur.next.containsKey(c)) {
                cur.next.put(c, new Node());
            }
            cur = cur.next.get(c);
        }
        // 单词的最后一个字符标记权重值
        cur.value = val;
    }

    public int sum(String prefix) {

        Node cur = root;

        // 找到前缀对应的最后一个字符对应的节点
        for (int i = 0; i < prefix.length(); i++) {
            char c = prefix.charAt(i);
            // 前缀不存在
            if (! cur.next.containsKey(c)) {
                return 0;
            }
            cur = cur.next.get(c);
        }

        return sum(cur);
    }

    /**
     * 遍历 node 以及 node的所有子节点的 value 值并求和
     * @param node 根节点
     * @return int
     */
    private int sum(Node node) {
        int res = node.value;

        // 遍历当前节点的所有子节点
        for (char c : node.next.keySet()) {
            res += sum(node.next.get(c));
        }
        return res;
    }
    
    /**
     * 节点
     */
    private class Node {
        public int value;                            // 权重值
        public HashMap<Character, Node> next;        // 下一个字符

        private Node(int value) {
            this.value = value;
            next = new HashMap<>();
        }

        private Node() {
            this(0);
        }
    }
}
```
