#### 先序遍历
```java
/**
例子：
    1
   / \
  2   5
 / \   \
3   4   6
对上面的树进行先序遍历后，得到：1 2 3 4 5 6
然后，每遍历一个节点，就将上一个节点的右指针更新为当前节点。我们按照下面的方式来遍历：

遍历到 2，把 1 的右指针指向 2。得到：1 -> 2 3 4 5 6
遍历到 3，把 2 的右指针指向 3。得到：1 -> 2 -> 3 4 5 6
... .... .....

*/
class Solution {
    
    private TreeNode prev = null;
    // 先序遍历(Pre-Order)：root -> left -> right
    public void flatten(TreeNode root) {
       if (root == null) return;
       // 先临时保存当前节点的左右子树
       TreeNode left = root.left;
       TreeNode right = root.right;

       // 展平当前节点 root
       if (prev == null) {
           prev = root;
       } else {
           // 将当前节点放置前一个节点的右节点上
           prev.right = root;
           // 置空左节点
           prev.left = null;
           // 更新前一个节点
           prev = root;
       }
       // 展平左节点
       flatten(left);
       // 展平右节点
       flatten(right);
    }
}
```

#### 后序遍历
```java
/**
例子：
    1
   / \
  2   5
 / \   \
3   4   6
对上面的树进行先序遍历后，得到：6 5 4 3 2 1
然后，每遍历一个节点就将当前节点的右指针更新为上一个节点。我们按照下面的方式来遍历：

遍历到 5，把 5 的右指针指向 6。得到：6 <- 5 4 3 2 1
遍历到 4，把 4 的右指针指向 5。得到：6 <- 5 <- 4 3 2 1
... ...

*/
class Solution {
    
    private TreeNode prev = null;
    // 后序遍历(Post-Order)：right -> left -> root
    public void flatten(TreeNode root) {
       if (root == null) return;
       // 先展平 right 节点
       flatten(root.right);
       // 再展平 left 节点
       flatten(root.left);
       // 最后展平当前的节点
       root.right = prev;
       root.left = null;
       prev = root;
    }
}
```