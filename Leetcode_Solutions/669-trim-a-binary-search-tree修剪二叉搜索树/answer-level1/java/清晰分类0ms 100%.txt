### 解题思路
递归

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
    public TreeNode trimBST(TreeNode root, int L, int R) {
        if (root==null)
            return null;
        if (root.val < L) // 当前节点值小于最小值，说明当前节点和左节点都不要了，直接把修改了右节点接上去
            root=trimBST(root.right, L, R);
        else if (root.val > R)// 当前节点值大于最大值，说明当前节点和右节点都不要了，直接把修改了左节点接上去
            root = trimBST(root.left, L, R);
        else if (root.val == L){// 当前节点值等于最小值，说明左节点都不要了，直接修改了右节点
            root.left=null;
            root.right=trimBST(root.right, L, R);
        } else if (root.val == R){// 当前节点值等于最大值，说明右节点都不要了，直接修改了左节点
            root.right=null;
            root.left=trimBST(root.left, L, R);
        } else {// 当前在值域范围内，左右都需要修改
            root.left=trimBST(root.left, L, R);
            root.right=trimBST(root.right, L, R);
        }
        return root;
    }

}
```