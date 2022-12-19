### 解题思路
此处撰写解题思路

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
 * @return {number}
 */
var countNodes = function(root) {
    let dfs = (node, res)=>{
        if(node!=null){
            dfs(node.left, res)
            res.push(node. val)
            dfs(node.right, res)
        }
    }
    let res = []
    dfs(root, res)
    return res.length
};
```