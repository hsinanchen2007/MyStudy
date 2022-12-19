### 解题思路
方法体外定义一个集合用来储存值作为返回结果.

判断该节点是否为空,为空则直接返回集合

判断该节点是否有子节点,有的话先将自身的val添加进集合中,再遍历子节点进行递归调用

最后返回结果

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
    private List<Integer> list = new ArrayList<>();
    public List<Integer> preorder(Node root) {
        if(root == null){return list;}

        if(root.children != null){
            list.add(root.val);
            for(Node n : root.children){
                preorder(n);
            }
        }
        return list;
    }
}
```