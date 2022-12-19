### 解题思路
产生的直径有两种可能性：1.包含root为顶点（对应max函数逗号前一半）
                    2.root不是该直径的顶点（对应max函数逗号后一半）

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

    public int diameterOfBinaryTree(TreeNode root) {

        if (root == null) return 0;

        //产生的直径有两种可能性：1.包含root为顶点（对应逗号前一半）
        //                    2.root不是该直径的顶点（对应逗号后一半）

        return Math.max(getDepth(root.left,0)+getDepth(root.right,0),
        Math.max(diameterOfBinaryTree(root.right),diameterOfBinaryTree(root.left))
        );

    }

    /**getDepth函数返回 root 为顶点的最大深度
    */
    public int getDepth(TreeNode root,int depth){ //上一层depth
        if(root == null) return depth;

        depth++;

        return Math.max(getDepth(root.left,depth),getDepth(root.right,depth));

    }
}
```