### 解题思路
![image.png](https://pic.leetcode-cn.com/538bf0c08906a5638ead24a34d423c7b09a429624c2f333e935d611e4af8c533-image.png)


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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(p==root||q==root) return root;//其中一个为根
        if(p.val<=root.val&&q.val>=root.val) return root;//分在根两边
        if(q.val<=root.val&&p.val>=root.val) return root;//分在跟两边
        if(q.val<root.val&&q.val<root.val) return lowestCommonAncestor(root.left,p,q);//都在左子树
        else return lowestCommonAncestor(root.right,p,q);//都在右子树
    }
}
```