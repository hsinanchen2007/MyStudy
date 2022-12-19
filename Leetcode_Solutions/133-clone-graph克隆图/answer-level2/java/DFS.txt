### 解题思路
深度递归克隆
值得注意的是用Map<Integer,Node> map来保存克隆过的节点，当遇到克隆过的节点时，直接从map中返回，不然程序无法结束。

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/
class Solution {
    public Node cloneGraph(Node node) {
        return cloneNode(node, new HashMap<>());
    }

    private Node cloneNode(Node node, Map<Integer,Node> map) {
        if(node == null)
            return null;
        if (map.containsKey(node.val)){
            //代表node已经克隆过
            return map.get(node.val);
        }
        Node temp = new Node(node.val);
        map.put(node.val,temp);
        List<Node> neighs = new ArrayList<>();
        for (Node neighbor : node.neighbors) {
            Node res = cloneNode(neighbor,map);
            neighs.add(res);
        }
        temp.neighbors = neighs;
        return temp;
    }
}
```