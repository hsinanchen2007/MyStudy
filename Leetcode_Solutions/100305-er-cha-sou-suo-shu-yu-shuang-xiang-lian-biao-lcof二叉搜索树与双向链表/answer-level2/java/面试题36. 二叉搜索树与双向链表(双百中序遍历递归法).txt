### 解题思路
本题主要分解成两个部分，1是中序遍历构建双向链表2.遍历后构建循环链表
因为循环双向链表所以要用到前驱节点pre，但是由于root节点没有前驱节点，所以先设一个虚拟的前驱节点
1.设虚拟前驱节点pre和指向头的head节点（用于返回结果的）
2.dfs先判断是否空，空就跳回上层递归
2.1非空就dfs左子树
2.2将前驱节点赋值给左子树的当前节点的左节点
2.3将左子树赋值给前驱节点的右节点，完成双向链表的基本要求
2.4将当前节点赋值给前驱节点
2.5dfs右子树
3.dfs结束后pre指向的是尾节点，所以要将虚拟头节点移到头节点处，将尾节点赋值给头节点的左子树，将头节点赋值给尾节点的右子树，返回头节点即可。

### 代码

```java
class Solution {
    Node head=new Node(0);
    Node pre=head;
    public Node treeToDoublyList(Node root) {
        if(root==null)return null;
        dfs(root);
        head=head.right;
        head.left=pre;
        pre.right=head;
        return head;
    }
    private void dfs(Node head){
        if(head==null)return;
        dfs(head.left);
        head.left=pre;
        pre.right=head;
        pre=head;
        dfs(head.right);
    }
}
```