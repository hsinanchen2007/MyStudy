### 解题思路
1 找到以二叉树中以每个节点开始的路径和等于sum的值即可。
注意此方法时间复杂度较高，因为每一次都要遍历每个节点的左右子树上的节点，但是比较容易理解。

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
    public int pathSum(TreeNode root, int sum) {
        if(root==null) return 0;
            return paths(root,sum)+pathSum(root.left,sum)+pathSum(root.right,sum);
    }
    public int paths(TreeNode root,int sum){
        if(root==null) return 0;
        int res=0;
        if(root.val==sum){
            res+=1;
        }
        res+=paths(root.left,sum-root.val);
        res+=paths(root.right,sum-root.val);
        return res;
    }
}
```