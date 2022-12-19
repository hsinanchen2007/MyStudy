### 解题思路
![屏幕快照 2020-03-08 下午2.32.43.png](https://pic.leetcode-cn.com/e42d6fbeec1dfbfe8ad0110079cf47b5601120b6006396658c4649d187fb82ae-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-08%20%E4%B8%8B%E5%8D%882.32.43.png)


### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    if(root==null || root===p || root===q)return root;
    var left = lowestCommonAncestor(root.left,p,q)
    var right = lowestCommonAncestor(root.right,p,q)
    if(left==null)return right;
    if(right==null) return left;
    if(left!=null && right!=null) return root;
};
```