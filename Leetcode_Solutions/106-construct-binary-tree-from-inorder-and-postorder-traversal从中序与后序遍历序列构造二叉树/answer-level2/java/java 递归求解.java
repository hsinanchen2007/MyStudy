## 解析
因为后序遍历为左右根。 中序遍历为左右根。
    所以后序遍历的最后一个元素为重建的二叉树的根节点的值。
    遍历中序遍历，直到找到和根节点值相同的位置。则此元素左边的都是根节点的左子树的元素，右边的都是根节点右子树的元素。
    通过递归很容易求出解。
## 代码
```java
public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder == null || inorder.length == 0 || postorder == null || postorder.length == 0 || inorder.length != postorder.length) {
            return null;
        }
        return help(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);

    }

    private TreeNode help(int[] inorder, int inStart, int inEnd, int[] postorder, int posStart, int posEnd) {
        //递归终止条件
        if (inStart > inEnd || posStart > posEnd) {
            return null;
        }
        //后续遍历的最后一个节点就是根节点
        TreeNode head = new TreeNode(postorder[posEnd]);
        int index = 0;
        while (inorder[inStart+index] != postorder[posEnd]) {
            index++;
        }
        head.left = help(inorder, inStart, inStart + index - 1, postorder, posStart, posStart + index - 1);
        head.right = help(inorder, inStart + index + 1, inEnd, postorder, posStart + index, posEnd - 1);
        return head;
    }
```