先搜索，再删除
注意删除的时候如果删除的正好是根节点，需要替换输出
关键是删除的时候，要分为三种情况：
1. 没有子树，直接删除
2. 有右子树或左子树，右子树或左子树上位
3. 有两个子树，用右子树根节点顶替待删除节点，并将右子树的左子树移动到待删除节点的左子树右下方

```java
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        TreeNode[] target = search(root, key, null);
        if (target == null) {
            return root;
        }
        if (root == target[0]) {
            return delete(target[0], target[1]);
        } else {
            delete(target[0], target[1]);
            return root;
        }
    }
    
    private TreeNode[] search(TreeNode root, int val, TreeNode father) {
        if (root == null) {
            return null;
        }
        if (root.val == val) {
            return new TreeNode[]{root, father};
        } else if (root.val < val) {
            return search(root.right, val, root);
        } else {
            return search(root.left, val, root);
        }
    }
    
    // root为待删除节点，father为root的父节点（可能为null），返回删除后的包括father在内的最高点
    private TreeNode delete(TreeNode root, TreeNode father) {
        if (root.left == null && root.right == null) {
            // 没有子树，直接删除
            if (father != null) {
                if (father.left == root) {
                    father.left = null;
                } else if (father.right == root) {
                    father.right = null;
                }
                return father;
            } else {
                return null;
            }
        } else if (root.left == null) {
            // 有右子树，右子树上位
            if (father != null) {
                if (father.left == root) {
                    father.left = root.right;
                } else if (father.right == root) {
                    father.right = root.right;
                }
                return father;
            } else {
                return root.right;
            }
        } else if (root.right == null) {
            // 有左子树，左子树上位
            if (father != null) {
                if (father.left == root) {
                    father.left = root.left;
                } else if (father.right == root) {
                    father.right = root.left;
                }
                return father;
            } else {
                return root.left;
            }
        } else {
            // 有两个子树
            // 用右子树根节点顶替根节点，并将右子树的左子树移动到根节点的左子树右下方
            TreeNode cur = root.right;
            TreeNode curLeft = cur.left;
            if (father != null) {
                if (father.left == root) {
                    father.left = cur;
                } else if (father.right == root) {
                    father.right = cur;
                }
            } else {
                father = cur;
            }
            
            cur.left = root.left;
            // 将右子树的左子树移动到根节点的左子树右下方
            if (curLeft != null) {
                TreeNode max = root.left;
                while(max.right != null) {
                    max = max.right;
                }
                max.right = curLeft;
            }
            return father;
        }
    }
}
```