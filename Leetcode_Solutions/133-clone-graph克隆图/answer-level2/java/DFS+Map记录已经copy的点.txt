执行结果：
通过
显示详情
执行用时 :
4 ms
, 在所有 Java 提交中击败了
86.62%
的用户
内存消耗 :
32.8 MB
, 在所有 Java 提交中击败了
63.23%
的用户
```
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
    Map<Node,Node> map = new HashMap<>();
    public Node cloneGraph(Node node) {
        if(node==null)return null;
        return get(node);
    }
    private Node get(Node n){
        if(map.containsKey(n)){
            return map.get(n);
        }
        Node newn = new Node(n.val,null);
        map.put(n,newn);
        List<Node> nl = new ArrayList<Node>();
        for(Node node:n.neighbors){
            nl.add(get(node));
        }
       newn.neighbors = nl;
        return newn;
    }
    
}
```
