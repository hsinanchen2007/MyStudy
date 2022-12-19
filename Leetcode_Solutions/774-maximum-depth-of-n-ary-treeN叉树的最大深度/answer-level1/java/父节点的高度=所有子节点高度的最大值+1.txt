### 解题思路
此处撰写解题思路
ArrayList求出最大值用`Collections.max()`
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
        if(root==null) return 0;
        if(root.children.isEmpty()) return 1;
        //求出每一个子树的高度，然后取最大值
        ArrayList<Integer> heights=new ArrayList<>();
        for(Node child:root.children){
            heights.add(maxDepth(child));
        }
        return Collections.max(heights)+1;
        
    }
}
```