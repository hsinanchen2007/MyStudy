### 解题思路
按照官方题解的思路，一次中序遍历解决

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
    private TreeNode last = new TreeNode(Integer.MIN_VALUE);
    private TreeNode[] swap = new TreeNode[2];
    private boolean hasFound = false;

    public void recoverTree(TreeNode root) {
        findSwap(root);
        recover(swap);
    }

    private void findSwap(TreeNode root) {
        if (root == null || hasFound) {
            return;
        }
        findSwap(root.left);
        if (root.val < last.val) {
            swap[1] = root;
            if (swap[0] == null) {
                swap[0] = last;
            } else {
                hasFound = true;
                return;
            }
        }
        last = root;
        findSwap(root.right);
    }

    private void recover(TreeNode[] swap) {
        int tmp = swap[0].val;
        swap[0].val = swap[1].val;
        swap[1].val = tmp;
    }
    
}
```