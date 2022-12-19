### 解题思路
递归终止条件：①当 当前节点为p或q 直接将其返回。②当 当前节点为null 说明递归到底还未找到p或q 说明p和q都不在该子树。将null返回

递归体：左右子树分别递归，并且保存。方便后续判断。
① 若左子树返回的值为空，说明p q都在右子树上，所以右子树中返回的那个节点便是所求。
② 同理，若右。。。。。。。。。。。。。。 
③ 左右子树返回值都不为空，说明该节点便是所求。

### 代码

```java
class Solution {
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null || root == p || root == q)
            return root;
        //须保存节点，因为后面需要判断
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        
        if(left == null)
            return right;
        if(right == null)
            return  left;
        return root;
    }
}
```