# 解题思路
**二叉搜索树（Binary Search Tree）**，（又：二叉查找树，二叉排序树）
- 它或者是一棵空树，或者是具有下列性质的二叉树： 
 	- 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 
 	- 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 
 	- 它的左、右子树也分别为二叉搜索树。

**最近公共祖先（最近公共节点）**
- **根据题目给定的前提：**
 	- 所有节点的值都是唯一的。 
 	- p、q 为不同节点且**均存在**于给定的二叉搜索树中。
-  **说明有以下几种情况：**
    1.  二叉树本身为空，root == null ，return root 
    1. p.val == q.val ,一个节点也可以是它自己的祖先
    2. p.val 和 q.val 都小于 root.val 
	    (两个子节点的值都小于根节点的值，说明它们的公共节点只能在二叉树的左子树寻找）
    3. p.val 和 q.val 都大于 root.val 
 	    (两个子节点的值都大于根节点的值，说明它们的公共节点只能在二叉树的右子树寻找）
    4. 如果上述的情况皆不满足，说明其公共节点既不在左子树也不在右子树上，只能为最顶端的公共节点，return root
 	    p.val < root.val  && q.val > root.val 或 p.val > root.val  && q.val < root.val 

---
# 解法一:递归查找
--执行用时：6 ms -内存消耗：41.7 MB
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
        if (p.val<root.val && q.val<root.val){
            return lowestCommonAncestor(root.left,p,q);
        }else if (p.val>root.val && q.val>root.val){
            return lowestCommonAncestor(root.right,p,q);
        }
        return root;
    }
}
```
---
# 解题二：非递归查找
----执行用时：6 ms -内存消耗：41.9 MB
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
        while (root!=null){
            if (p.val<root.val && q.val<root.val){
                root=root.left;
            }else if (p.val>root.val && q.val>root.val){
                root=root.right;
            }else{
                break;
            }
        }
        return root;
    }
}
```
---