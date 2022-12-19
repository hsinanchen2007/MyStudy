**题解**
采用了三个全局指针去分别代表  head tail pre;
```java
class Solution {
    public Node head = null,pre = null,tail=null;
    public Node treeToDoublyList(Node root) {
        if(root==null){
            return root;   
        }
        inorder(root);
        head.left = tail;
        tail.right = head;
        return head;
    }
    public void inorder(Node root){
        //递归出口
        if(root==null) return ;
        //访问左子树
        inorder(root.left);
        //将当前节点和上一个节点连接
        if(pre==null) head=root;
        else pre.right=root;
        root.left=pre;
        pre=root;
        tail=root;
        //访问右子树
        inorder(root.right);
        return ;
    }
}
```
