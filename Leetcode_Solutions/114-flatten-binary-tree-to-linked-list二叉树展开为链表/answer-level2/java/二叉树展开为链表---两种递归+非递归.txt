### 1、递归 --- 后序遍历顺序
按照后序遍历的顺序展开二叉树，使用递归实现

### 代码
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public void flatten(TreeNode root) {
        if (root == null){
            return;
        }
        flatten(root.left);
        flatten(root.right);
    
        if(root.left != null){
            TreeNode lf = root.left;
            while(lf.right != null){
                lf = lf.right;
            }
            lf.right = root.right;
            root.right = root.left;
            root.left = null;
        }
    }
}
```

### 2、递归 --- 修改遍历顺序，省去查找左子树最右节点
第一种方法中，需要每次查找左子树的最右节点，较为麻烦。
先展开右子树，记录展开链表的起始节点pre，后展开左子树，将左子树展开链表的结尾节点的右指针指向节点pre，省去寻找左子树最右节点的步骤。

### 代码
```java
class Solution {
    private TreeNode prev = null;
    public void flatten(TreeNode root) {
        if (root == null)
            return;
        flatten(root.right);
        flatten(root.left);
        root.right = prev;
        root.left = null;
        prev = root;
    }
}
```

### 3、非递归 --- 迭代实现
将第一种方法改为迭代实现

### 代码

```java
class Solution {
    public void flatten(TreeNode root) {
        if (root == null){
            return;
        }
        TreeNode node = root;
        while (node != null){
            if(node.left != null){
                TreeNode lf = node.left;
                while(lf.right != null){
                    lf = lf.right;
                }
                lf.right = node.right;
                node.right = node.left;
                node.left = null;
            }
            node = node.right;
        }
    }
}
```