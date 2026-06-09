### 解题思路
本题的递归结束条件稍微复杂，一开始我想的是先判断是否满足递归结束条件，发现该条件写起来比较麻烦。
因为要考虑到左右孩子其中之一与递归的当前节点值相等，所以干脆先递归，若不满足两个递归条件 则直接返回当前节点

### 代码

```java
class Solution {
   
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(p.val < root.val && q.val < root.val)
            return lowestCommonAncestor(root.left,p,q);
        if(p.val > root.val && q.val > root.val)
            return lowestCommonAncestor(root.right,p,q);
        return root;
    }
}

```