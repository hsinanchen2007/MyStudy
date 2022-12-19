### 递归（通过）
与树有关的都涉及到递归，我们先来分析一下这个题递归的基线条件
> 1.如果根节点为空，那就啥也没有，返回根节点就好了
> 2.如果p或者q为根节点，那还是返回根节点，因为此时p或者q就是p和q的最近公共祖先

然后我们来看一下递归的思路是什么，有三种情况
> 1.如果p和q分别在某个根节点的左右子树，那这个根节点就是它们的最近公共祖先
> 2.如果p和q都在某个根节点的左子树，那在处在上面的就是这两个节点的最近公共祖先
> 3.如果p和q都在某个根节点的右子树，那么同样的，处在上面的就是这两个节点的最近公共祖先

所以这里我们就是先在所有节点的左子树找p和q，然后在所有节点的右子树去找p和q，如果在左子树和右子树都找到了，因为树中节点的值是唯一的，且p和q是不同的，所以此时p，q分别在左右子树，直接返回此时的根节点就ok，如果左子树没有找到或者右子树没有找到，证明p和q均在左子树或者右子树，那就直接返回找到的那个值就好了，因为递归是从上到下的，所以先发现的一定是位置比较高的那个。
<br>
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
        if(root==null) return null;
        
        if(p.val==root.val||q.val==root.val) return root;
        
        //在根节点的左子树寻找p或者q
        TreeNode left=lowestCommonAncestor(root.left,p,q);
        //在根节点的右子树寻找p或者q
        TreeNode right=lowestCommonAncestor(root.right,p,q);
        
        if(left!=null&&right!=null){
            return root;
        }
        
        return left==null? right:left;
    }
}
```