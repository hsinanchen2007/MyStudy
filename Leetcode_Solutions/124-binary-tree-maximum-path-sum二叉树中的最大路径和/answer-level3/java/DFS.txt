### 解题思路
这题本来不会做，但是受到了今天打卡题思路的启发。
要计算二叉树中的最大路径和，我们可以计算以他的孩子节点为根的子树的最大路径和，然后根节点依据左右树的最大路径和，进行取舍。

我们从下往上回溯时，要记得选择当前树的根节点，只有通过根节点，才能抵达该根节点的子树。
判断最大值的时候，要记得比较 左子树 + 根 + 右子树 与 当前最大值的大小关系。


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
    public int maxPathSum(TreeNode root) {
        int[] res = new int[1];
        res[0] = Integer.MIN_VALUE;
        dfs(res, root);
        return res[0];
    }

    private int dfs(int[] res, TreeNode root){
        if (root == null)
            return 0;
        int left = dfs(res, root.left);
        int right = dfs(res, root.right);
        int max = Math.max(left, right);
        int result = 0;
        //不选孩子节点
        if (max <= 0){
            result = root.val;
        }
        //选孩子节点
        else {
            result = root.val + max;
            if (left + right + root.val > res[0])
                res[0] = left + right + root.val;
        }
        if (result > res[0])
            res[0] = result;
        return result;
    }
}
```