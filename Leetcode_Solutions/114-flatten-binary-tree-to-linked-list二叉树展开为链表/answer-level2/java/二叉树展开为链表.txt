### 解题思路
1. 方法1是通过后序遍历的思想，先将左子节点捋直，然后放到根的右边，然后将右边的放在其后。
2. 方法2的思想较为巧妙，同样时后序遍历，但是是先右后左，这样的好处是右孩子天生就在左孩子后面，所以只要顺序连接起来即可，没有了插入的部分。

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
class Solution1 {
    public void flatten(TreeNode root) {
        if(root == null) return;
        flatten(root.left);
        flatten(root.right);
        if(root.left != null){
            TreeNode tmp = root.right;
            root.right = root.left;
            root.left = null;
            TreeNode move = root.right;
            while(move.right != null) move = move.right;
            move.right = tmp;
        }
    }
}

class Solution2 {
    TreeNode last = null;
    public void flatten(TreeNode root) {
        if(root == null) return;
        flatten(root.right);
        flatten(root.left);
        root.right = last;
        root.left = null;
        last = root;
    }
}
```