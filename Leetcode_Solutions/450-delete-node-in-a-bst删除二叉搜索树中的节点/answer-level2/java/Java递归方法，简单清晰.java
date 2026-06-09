思路：
首先根据BST的性质查找到与key相等的节点r，判断以r为根的树的情况
1） r为叶子节点
     直接删除
2） r的左右子树都全
     用左子树的最大值覆盖要删除的节点，然后在子树中删除多余的节点。
3） r一边有子树
     返回对应的子树的节点

```
public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null;
        if (root.val < key) root.right = deleteNode(root.right, key);
        if (root.val > key) root.left = deleteNode(root.left, key);
        if (root.val == key) {
            int left = root.left != null ? 1 : 0;
            int right = root.right != null ? 1 : 0;
            int kids = left + right;
            switch (kids) {
                case 0:
                    return null;
                case 1:
                    return (left == 1) ? root.left : root.right;
                case 2:
                    //左子树中最大节点
                    TreeNode cur = root.left;
                    while(cur.right != null) {
                        cur =cur.right;
                    }
                    // 精彩之处：用左子树的最大值覆盖要删除的节点，然后在子树中删除多余的节点。
                    root.val = cur.val;
                    root.left = deleteNode(root.left, cur.val);
                default:
                    break;
            }
        }
        return root;
    }
```