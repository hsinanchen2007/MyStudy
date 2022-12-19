### 解题思路


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
    private int res = 0;
    public int maxDepth(Node root) {
        dfs(root,1);
        return res;
    }
    
    private void dfs(Node root,int h){
        if(root == null)
            return ;
        if(h > res)
            res = h;
        int len = root.children.size();
        for(int i = 0;i < len;i++)
            dfs(root.children.get(i),h + 1);
    }
}
```