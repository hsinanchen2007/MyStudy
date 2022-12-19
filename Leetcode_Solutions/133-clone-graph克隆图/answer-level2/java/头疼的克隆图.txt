### 解题思路
思路很简单，首先建立一个克隆点与原始点的映射关系map，然后根据广度优先（深度优先也可以）遍历所有的节点，
然后对每个原始点的邻居节点进行讨论，若邻居访问过，则对这个点映射的克隆的邻居加此点，否则新建一个克隆对象；
第一次错误的原因：整体思路没啥问题，错在我所有新建的克隆对象的邻居都指向了一个引用对象，贼傻逼的错误。
### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {}

    public Node(int _val,List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    public Node cloneGraph(Node node) {
        Map<Node,Node> map=new HashMap<>();
        Node firstNode=new Node(node.val,new ArrayList<>());
        map.put(node,firstNode);
        Queue<Node> queue=new LinkedList<>();
        queue.offer(node);
        while(queue.peek() != null){
            Node popNode=queue.poll();
            Node mapNode=map.get(popNode);
            for(Node neigh:popNode.neighbors){
                Node secondNode=null;
                // 如果在map中表示访问过，不动他，否则将其加入map，同时加入队列
                if(map.containsKey(neigh)){
                    secondNode=map.get(neigh);
                } else{
                    secondNode=new Node(neigh.val,new ArrayList<>());
                    queue.offer(neigh);
                    map.put(neigh,secondNode);
                }
                mapNode.neighbors.add(secondNode);
            }
        }
        return firstNode;

        
    }
}
```