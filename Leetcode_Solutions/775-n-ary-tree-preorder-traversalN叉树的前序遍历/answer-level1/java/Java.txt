

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
    public List<Integer> preorder(Node root) {
        ArrayList<Integer> list = new ArrayList<>();
        _preorder(root,list);
        return list;
    }
    private void _preorder(Node current, ArrayList<Integer> list) {
        if(current!=null)
        {
            //访问当前节点
            list.add(current.val);
            //递归访问子节点
            current.children.forEach(i->_preorder(i,list));
        }
    }
}
```