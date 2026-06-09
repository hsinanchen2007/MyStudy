### 解题思路
由题目与案例可以得出，需要添加的next大致分为三种情况：
（1）最右端节点指向null
（2）每个节点的左右孩子节点由左指向右
（3）不同子树之间最右端节点指向最左端节点
根据这个思想，分别递归调用三个简单方法完成上述三种情况
### 代码

```java
class Solution {
    public Node connect(Node root) {
        if (root == null) return root;
        bfs3(root);
        if (root.left != null){
            bfs1(root);
            if (root.left.right != null){
                bfs2(root.left,root.right);
            }
        }
        return root;
    }
    //处理同一节点下左右节点的连接
    public void bfs1(Node current){
        if (current.left == null) return;
        current.left.next = current.right;
        bfs1(current.left);
        bfs1(current.right); 
    }
    //处理不同子树下节点之间的连接
    public void bfs2(Node current,Node next){
        current.right.next = next.left;
        if (current.left.left != null){
            //子树的上一个根节点相同
            bfs2(current.left,current.right);
            bfs2(next.left,next.right);
            //子树的上一个根节点不同
            bfs2(current.right,next.left); 
        } 
    }
    //处理最右端节点的连接
    public void bfs3(Node current){
        current.next = null;
        if (current.right != null) bfs3(current.right);
    }
}
```