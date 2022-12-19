### 解题思路
递归遍历一遍，每层记录对应的层级

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
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if(root == null) return []
    let res = []
    function traversal(node, deep) {
        if(node == null) return
        // res.push(node.val)
        
        if(!res[deep]) {
            res[deep] = []
        }
        
        res[deep].push(node.val)

        traversal(node.left, deep + 1)
        traversal(node.right, deep + 1)
    }
    // res.push([root.val])
    traversal(root,0)
    return res
};
```