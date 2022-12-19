![image.png](https://pic.leetcode-cn.com/456ac9d9e66fd4107f7a6bc104279408a522641c66dc81ada0208a22e48b9cf2-image.png)
把一棵树t2合并到另外一棵树上t1上，
``
public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if(t1 ==null&& t2 ==null){return null;}
        if(t1 == null)return t2;
        if(t2==null) return t1;
        t1.val = t1.val+t2.val;
        t1.left=mergeTrees(t1.left,t2.left);
        t1.right=mergeTrees(t1.right, t2.right);
        return t1;

    }

```
和226一样,226是对数交换左右有孩子，617是左右孩子结点的和相加。