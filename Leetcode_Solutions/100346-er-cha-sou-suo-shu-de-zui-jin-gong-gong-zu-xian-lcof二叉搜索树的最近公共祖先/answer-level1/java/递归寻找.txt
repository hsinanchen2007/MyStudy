### 解题思路
如果p与q相等，随便返回一个；如果p与q有一个与root相等，返回root；如果p与q分布在root两边返回root；否则，在root的一个方向中向下寻找

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
        if(p.val==root.val || q.val==root.val){
            return root;
        }
        if(p.val>q.val){
            if(p.val>root.val && q.val<root.val){
               return root;
            }

        }else if(p.val<q.val){
            if(p.val<root.val && q.val>root.val){
                return root;
            }

        }else{
            return p;
        }
        if(p.val<root.val){
            return lowestCommonAncestor(root.left,p,q);
        }else{
            return lowestCommonAncestor(root.right,p,q);
        }
    }
}
```