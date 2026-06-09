### 解题思路
递归的条件是当res不在p和q中间时候，就会向左或向右递归，这样做的目的就是节点的左移和右移，所以可以用循环来代替。

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




public class Solution {



    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        //二叉搜索树的性质有一个就是父节点大于所有子节点（包括以子节点为父节点的节点）
        // 小于右节点
        TreeNode res = root;
        TreeNode p1 = p.val < q.val ? p:q;
        TreeNode q1 = q.val > p.val ? q:p;
        while(res!=null){
            if(res.val > p1.val && res.val < q1.val || res.val == p1.val || res.val == q1.val) return res;
            else{
                // 如果root都大于p和q节点，则说明p和q都在root的左边，且还可以在向左边节点递归
                if( res.val > p1.val && res.val > q1.val) res = res.left;
                // 如果root都小于于p和q节点，则说明p和q都在root的右边，且还可以在向右边节点递归
                if( res.val < p1.val && res.val < q1.val) res = res.right;
            }
        }
        return  null;

    }
}
```