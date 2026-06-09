### 解题思路
本题解是 找规律。

题目要我们找的是每个节点的右侧节点，而这棵树又是一颗*完美二叉树*，因此就很简单了。

左儿子的右侧节点就是父节点的右儿子，即兄弟节点；右儿子的右侧节点就是父节点的右侧节点的左儿子。这样就可以写代码了
### 代码

```java
class Solution {
    
    Node preOrder(Node root,Node next){
        if(root==null)return null;
        root.next=next;
        
        preOrder(root.left,root.right);
        preOrder(root.right,root.next==null?null:root.next.left);
        return root;
    }
    
    public Node connect(Node root) {
       return  preOrder(root,null);
    }
}
```