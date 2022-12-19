### 解题思路
分为3中情况：
1 如果根节点的值小于L，则表明L到R之间的数在右子树上。
2 如果根节点的值大于R，则表明L到R之间的数在左子树上。
3 如果根节点的值在L与R之间，则递归左右子树。

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
    public int rangeSumBST(TreeNode root, int L, int R) {
     if(null==root) return 0;
        if(root.val>R)
        return rangeSumBST(root.left,L,R);
        if(root.val<L)
        return rangeSumBST(root.right,L,R);
        
        return root.val+rangeSumBST(root.left,L,R)+rangeSumBST(root.right,L,R);
    }

}
```