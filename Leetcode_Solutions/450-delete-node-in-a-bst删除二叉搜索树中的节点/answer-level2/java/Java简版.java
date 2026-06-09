这道题目主要考察两个点。
第一个是BST的性质，中序遍历是从小到大的，可以用二分查找的方式搜索要删除的结点。
第二个考察点是删除结点部分的处理：
1. 叶子结点的话直接删除返回null即可；
2. 如果有左子树或右子树，则直接用子树代替被删除结点；
3. 若既有左子树又有右子树，则用被删除结点的前一个小于它的结点或后一个大于它的结点代替，然后调整树的结构。我这里省略了调整树的结构，直接把被删除结点的右子树挂在了它前一个最大的结点右边。这样做其实是懒人做法，没有管它的高度，不过题目不要求平衡二叉树，所以也是可以通过的。

![image.png](https://pic.leetcode-cn.com/b5554e9f5fe9809ae6069d899aaa241166d22930ec6f564064047942f166959b-image.png)


```
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        return delete(root, key);
    }
    //辅助函数用来删除以root为根结点中的目标结点，返回新的跟结点
    private TreeNode delete(TreeNode root, int key) {
        if (root == null) return null;
        if (root.val == key) {
            //被删除结点的左子树为空，则返回右子树
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                //被删除结点的右子树为空，则返回左子树
                return root.left;
            } else { 
                //被删除结点的左右子树都不为空，则找到左子树的最右边的结点，将被删结点的右子树挂在它的右边，返回被删结点的左子树
                TreeNode rightMost = root.left;
                while (rightMost.right != null) {
                    rightMost = rightMost.right;
                }
                rightMost.right = root.right;
                return root.left;
            }
        } else if (root.val > key) {
            // 被删除的结点在左子树
            root.left = delete(root.left, key);
        } else {
            // 被删除的结点在右子树
            root.right = delete(root.right, key);
        }
        return root;
    }
}
```
