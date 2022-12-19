### 解题思路
如果两个节点都大于根节点，那么根节点肯定不是最近的公共父节点，至少根节点的右节点比根节点更近，反之，如果两个节点都小于根节点，那根节点的左节点比根节点更近。依次遍历左节点或右节点，直至p、q不满足都是某个节点的左子树或右子树，那么这个节点就是最近的公共父节点

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
        int pVal = p.val;
        int qVal = q.val;
        TreeNode node = root;

        while(node != null){
            if(pVal > node.val && qVal > node.val){
                node = node.right;
            }else if(pVal < node.val && qVal < node.val){
                node = node.left;
            }else{
                return node;
            }
        }
        return node;
    }
}
```