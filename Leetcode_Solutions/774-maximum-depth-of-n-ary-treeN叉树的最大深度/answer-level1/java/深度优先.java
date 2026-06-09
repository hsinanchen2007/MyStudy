### 解题思路
深度优先

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

    public int maxDepth(Node root) {
        if(root == null){
            return 0 ;
        }
        return caculate(root) + 1;
    }

    public static int caculate(Node root){
        if(root == null){
            return 0;
        }

        int maxDepth = 0;

        for(Node node : root.children){
            int dep = caculate(node) + 1;
            maxDepth = Math.max(dep, maxDepth);
        }
        return maxDepth;
    }
}
```