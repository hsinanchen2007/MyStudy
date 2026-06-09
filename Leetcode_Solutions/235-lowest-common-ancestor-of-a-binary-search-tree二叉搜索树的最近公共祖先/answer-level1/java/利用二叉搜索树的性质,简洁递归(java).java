在用户li-xin-lei的逻辑基础上调整了一下代码：
# **题目思路：**
如果 p 和 q 在 root 的两边，那么 root 就是 p 和 q 的最低的公共祖先，这种情况包含三种具体的情况：
1.p 和 q 在 root 的两边；
2.p 就是 root，q 在 root 的哪边无所谓；
3.q 就是 root，p 在 root 的哪边无所谓；
如果不是上面的情况，p 和 q 要么全在 root 的左边，要么全在 root 的右边，这时只需递归的去 root 的左子树或右子树中找 p 和 q 的最低公共祖先.


```
public class LowestCommonAncestor {
    public TreeNodeInt LowestCommonAncestor(TreeNodeInt root,TreeNodeInt p,TreeNodeInt q){
        if(p==null||q==null||root==null){
            return null;
        }
        //遍历左子树
        if(p.val<root.val&&q.val<root.val){
            return LowestCommonAncestor(root.left,p,q);
        }
        //遍历右子树
        if(p.val>root.val&&q.val>root.val){
            return LowestCommonAncestor(root.right,p,q);
        }
        //如果左边大于等于，右边小于等于，直接返回root
        if(p.val<=root.val&&q.val>=root.val){
            return root;
        }

        return root;
    }
}
```
