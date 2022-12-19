### 解题思路
1. 首先递归函数用于返回当前子树所有节点的和（原树）。
2. 当搜索右子树时，将上层节点传入的附加值向下传递；当搜索左子树时，则将上层节点传入的附加值和当前节点的值相加向下传入。
3. 每层搜索时注意保存当前节点原本的数值，用于向上返回。

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

    public int dfs( TreeNode root , int add ){
        if ( root == null ) return 0;
        int leftSum = 0;
        int rightSum = 0;
        int oldVal = root.val;
        root.val += add;
        /* search right child first */
        if ( root.right != null ){
            rightSum = dfs(root.right , add);
        }
        root.val += rightSum;
        if ( root.left != null ){
            leftSum = dfs(root.left , root.val);
        }
        return leftSum + rightSum + oldVal;
    }

    public TreeNode convertBST(TreeNode root) {
        dfs(root,0);
        return root;
    }

}
```