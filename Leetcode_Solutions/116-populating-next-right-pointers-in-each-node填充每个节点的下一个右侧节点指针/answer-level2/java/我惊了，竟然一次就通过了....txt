```
class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return root;
        }
        connect(root.left, root.right);
        return root;
    }
    
    private void connect(Node left, Node right) {
        if(left == null && right == null) {
            return;
        }
        
        Node l_root = connect(left);
        Node r_root = connect(right);
        
        while(l_root != null && r_root != null) {
            l_root.next = r_root;
            l_root = l_root.right;
            r_root = r_root.left;
        }
        
    }
}
```
本来都打算看答案了。
思路其实很简单，就是相当于把**两颗**已经**连接好的树**，再次连接成一个新的树。所以就只要将**左边**的树的**右节点**指向**右边**的树的**左节点**就行了