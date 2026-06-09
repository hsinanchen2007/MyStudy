这道题目是图的遍历，节点遍历我们很熟悉，要么dfs，要么dfs。关键点是：**图的边怎么复制**。为了复制两个节点之间边的关系，我们用一个map去记录原节点和新节点之间的对应关系，这样遍历节点的的时候我们就可以通过map 查到复制节点的，把他们的边复制上。我们先采用bfs的方式来复制图。
```
class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) return null;
        Map<Node, Node> map = new HashMap<>();
        Queue<Node> queue = new LinkedList<>();
        queue.add(node);
        Node copyNode = new Node();
        copyNode.val = node.val;
        map.put(node, copyNode);

        while (!queue.isEmpty()) {
            Node current = queue.poll();
            if (current.neighbors == null) {
                continue;
            }
            
            if (map.get(current).neighbors == null) {
                map.get(current).neighbors = new LinkedList<>();
            }

            List<Node> neighbors = current.neighbors;
            List<Node> copiedneighbors = new LinkedList<>();
            for (Node nei***or : neighbors) {
                if (!map.containsKey(nei***or)) {
                    queue.add(nei***or);
                    Node tmp = new Node();
                    tmp.val = nei***or.val;
                    map.put(nei***or, tmp);
                }
                map.get(current).neighbors.add(map.get(nei***or));
            }
        }
        return map.get(node);
    }
}
```

采用dfs的递归方式来复制图。

```
class Solution {
    public Node cloneGraph(Node node) {
        Map<Node, Node> resNode2CopyNode = new HashMap<>();
        return helper(node, resNode2CopyNode);
    }

    public Node helper(Node node, Map<Node, Node> resNode2CopyNode) {
        if (node == null) return null;
        if (!resNode2CopyNode.containsKey(node)) {
            Node tmp = new Node();
            tmp.val = node.val;
            resNode2CopyNode.put(node, tmp);
        }
        Node copy = resNode2CopyNode.get(node);
        if (node.neighbors == null) {
            return copy;
        }

        copy.neighbors = new LinkedList<>();
        List<Node> neighbors = node.neighbors;
        for (Node nei***or : neighbors) {
            Node copyNei***or = null;
            if (resNode2CopyNode.containsKey(nei***or)) {
                copyNei***or = resNode2CopyNode.get(nei***or);
            } else {
                copyNei***or = helper(nei***or, resNode2CopyNode);
            }
            
            copy.neighbors.add(copyNei***or);
        }    
        return copy;
    }
}
```
采用dfs迭代的方式来解。
```
class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) return null;
        Map<Node, Node> resNode2CopyNode = new HashMap<>();
        Stack<Node> stack = new Stack<>();
        stack.push(node);
        Node copy = new Node();
        copy.val = node.val;
        resNode2CopyNode.put(node, copy);
        while (!stack.isEmpty()) {
            Node current = stack.pop();
            List<Node> neighbors = current.neighbors;
            if (neighbors == null) {
                continue;
            }

            Node copyNode = resNode2CopyNode.get(current);
            if (copyNode.neighbors == null) {
                copyNode.neighbors = new LinkedList<>();
            }
            
            for (Node nei***or : neighbors) {
                Node copyNei***or = null;
                if (resNode2CopyNode.containsKey(nei***or)) {
                    copyNei***or = resNode2CopyNode.get(nei***or);
                } else {
                    copyNei***or = new Node();
                    copyNei***or.val = nei***or.val;
                    resNode2CopyNode.put(nei***or, copyNei***or);
                    stack.push(nei***or);
                }
                copyNode.neighbors.add(copyNei***or);
            }
        }
        return copy;
    }
}
```
