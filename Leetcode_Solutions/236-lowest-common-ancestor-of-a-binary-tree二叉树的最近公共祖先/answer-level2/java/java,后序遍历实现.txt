### 解题思路
 思路1，因为是找p q公共祖先，所以使用后序来处理，祖先后访问
  如果node的 left right 已经遍历后发现命中了 p q，则证明node是最近的公共祖先，返回
  因为存在 node本身等于 p或者q的，当这种情况出现时，把 left 或者 right中false 改为 true
  因为如果left 或者 right 都为true则成功，如果只有一个为true，表明了node这颗子树本身命中了 p或者q
  把结果返回给调用者就知道node子树，是处于left or right。
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
       private TreeNode p;
    private TreeNode q;
    private TreeNode ans = null;

    private boolean postOrder(TreeNode root) {
        if (null == root)
            return false;
        boolean left = postOrder(root.left);
        boolean right = postOrder(root.right);
        // 处理，p本身是最深 公共祖先
        if (root == p || root == q) {
            if (left)
                right = true;
            else
                left = true;
        }
        if (left && right) {
            ans = root;
            return false;
        }
        return left | right;
    }

    /**
     * 思路1
     *
     * @param root
     * @param p
     * @param q
     * @return
     */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null)
            return null;
        if (q == null)
            return null;
        if (p == null)
            return null;
        this.p = p;
        this.q = q;
        postOrder(root);
        return ans;
    }
}
```