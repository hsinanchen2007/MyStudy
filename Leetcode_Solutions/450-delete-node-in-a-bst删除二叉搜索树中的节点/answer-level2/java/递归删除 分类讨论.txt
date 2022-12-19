[更多LeetCode题解](https://github.com/heyihui001/LeetCode)
```java
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) {
            return null;
        }
        // 若待删除的值在左子树
        if(key < root.val) {
            // 递归更新左子树
            root.left = deleteNode(root.left, key);
        // 若待删除的结点在右子树
        }else if(key > root.val) {
            // 递归更新右子树
            root.right = deleteNode(root.right, key);
        // 若当前结点为待删除的结点，分类讨论
        }else {
            // 1. 待删除的结点左右子树都存在，有两种更新策略：             
            if(root.left != null && root.right != null) {
                // 1.用当前结点的左子树的最大值取代当前结点的值，并将左子树中的最大值结点删除；
                root.val = findMax(root.left);
                root.left = deleteNode(root.left, root.val);
                // 2.用当前结点的右子树的最小值取代当前结点的值，并将右子树中的最小值结点删除。
                // root.val = findMin(root.right);
                // root.right = deleteNode(root.right, root.val);
                // p.s.左子树的最大值的结点的右子树为空，右子树的最小值结点的左子树为空，删除规则同2或3

            // 2.待删除的结点只存在右子树
            }else if(root.left == null) {
                // 可直接用右子树结点替换当前结点
                root = root.right;
            // 3.待删除的结点只存在左子树，同2
            }else if(root.right == null) {
                root = root.left;
            // 4.待删除的结点左右子树都不存在
            }else {
                // 将该结点置空即可
                root = null;
            }
        }
        
        return root;
    }
    
    // 查找BST中的最大值
    // 一直向右寻找，直到某个结点的右子树为空，返回该值
    private int findMax(TreeNode root) {
        if(root.right == null) {
            return root.val;
        }
        
        return findMax(root.right);
    }
    
    // 查找BST中的最小值
    // 一直向左寻找，直到某个结点的左子树为空，返回该值
    private int findMin(TreeNode root) {
        if(root.left == null) {
            return root.val;
        }
        
        return findMin(root.left);
    }
}
```
