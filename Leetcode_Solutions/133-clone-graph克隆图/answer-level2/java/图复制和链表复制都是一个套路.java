### 解题思路
图复制和链表复制都是一个套路

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
        if (node==null) return null;
        /**
         * 复制每个节点,然后组装关系
         */
        HashMap<Node, Node> map = new HashMap<>();
        ArrayList<Node> list = new ArrayList<>();
        ArrayList<Node> list1 = new ArrayList<>();
        HashSet<Node> set = new HashSet<>();
        Queue<Node> queue = new LinkedList<Node>();
        queue.add(node);
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Node node1 = queue.poll();
                Node tmp = copy(node1);
                list.add(tmp);
                list1.add(node1);
                map.put(node1, tmp);
                set.add(node1);
                for (Node neighbor : node1.neighbors) {
                    if (!set.contains(neighbor)) {
                        queue.add(neighbor);
                    }
                }
            }
        }
        for (int i = 0; i < list.size(); i++) {
            Node n = list.get(i);
            Node n1 = list1.get(i);
            for (Node neighbor : n1.neighbors) {
                Node node1 = map.get(neighbor);
                n.neighbors.add(node1);
            }
        }
        return list.get(0);
    }


    private Node copy(Node node) {
        if (node == null) return null;
        return new Node(node.val);
    }
    
    
    
    
    
    
    
    
    
    
    
    
public Node cloneGraph1(Node node) {
        HashMap<Node, Node> map = new HashMap<>();
        return   dfs(node,map);
    }

    private Node dfs(Node node,HashMap<Node, Node> map) {
        Node node1 = new Node();
        if (node == null) return null;
        if (map.containsKey(node)) return map.get(node);
        map.put(node,node1);
        node1.val = node.val;
        for (int i = 0; i < node.neighbors.size(); i++) {
            node1.neighbors.add(dfs(node.neighbors.get(i),map));
        }
        return node1;
    }
}
```