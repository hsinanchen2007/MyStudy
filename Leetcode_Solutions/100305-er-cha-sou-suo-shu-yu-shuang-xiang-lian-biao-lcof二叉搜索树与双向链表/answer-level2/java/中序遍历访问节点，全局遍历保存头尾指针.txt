### 代码

```java
class Solution {
    Node head=null,pre=null,tail=null;
    public Node treeToDoublyList(Node root) {
        if(root==null) return root;
        //中序遍历访问节点并连接
        inorder(root);
        //连接头尾节点
        head.left=tail;
        tail.right=head;
        return head;
    }
    private void inorder(Node root){
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