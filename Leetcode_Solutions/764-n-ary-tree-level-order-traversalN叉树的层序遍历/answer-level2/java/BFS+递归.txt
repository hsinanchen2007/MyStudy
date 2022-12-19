
### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    //递归+BFS
   List<List<Integer>> res = new ArrayList();
    public List<List<Integer>> levelOrder(Node root) {
        if(root == null){
            return res;
        }
        BFS(root,0);
        return res;
    }
    private void BFS(Node node,int level){
        if(level == res.size()){
            res.add(new ArrayList<Integer>());
        }
        res.get(level).add(node.val);
        List<Node> childrenList = node.children;
        if(childrenList != null){
            for(Node children:childrenList){
                BFS(children,level+1);
            }
        }
    }
}
```