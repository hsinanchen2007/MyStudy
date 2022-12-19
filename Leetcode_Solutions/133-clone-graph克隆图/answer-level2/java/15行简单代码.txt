### 解题思路
都在代码里头了

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
       if(node==null) return null;
		return copy(node);
	}
	HashMap<Integer, Node> map = new HashMap<>();
	Node copy(Node src) {
		if (map.containsKey(src.val)) return map.get(src.val);
		Node node = new Node(src.val);
        map.put(src.val, node);
		for (Node temp : src.neighbors)
			node.neighbors.add(copy(temp));		
		return node;
	}
}
```