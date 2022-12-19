### 解题思路
思路清晰，叫我第一☝️（dfs专练）

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
 * @param {number} sum
 * @return {number[][]}
 */
let res
var pathSum = function(root, sum) {
    res = []
    dfs(root, [], sum)
    return res
};

function dfs(root, path, sum){
    if(!root) return
    sum -= root.val
    if(sum == 0 && !root.left && !root.right){
        res.push([...path, root.val])
        // path.pop()
        return
    }
    path.push(root.val)
    dfs(root.left, path, sum)
    dfs(root.right, path, sum)
    path.pop()
}
```