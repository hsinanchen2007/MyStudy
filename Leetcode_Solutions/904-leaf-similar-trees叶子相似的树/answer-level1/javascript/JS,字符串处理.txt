### 解题思路
&emsp;&emsp;一般是遍历值存进数组，我这里直接格式化成字符串进行比较，加入分隔符是避免，例如[1,11],[11,1]这种情况。

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
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
var leafSimilar = function(root1, root2) {
    function dfs(root){
        if(root == null) return '';
        if(root.left == root.right){
            return root.val + '|';
        }
        return dfs(root.left) + dfs(root.right);
    }
    return dfs(root1) == dfs(root2);
};
```