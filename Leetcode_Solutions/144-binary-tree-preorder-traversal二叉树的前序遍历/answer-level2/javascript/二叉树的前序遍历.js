### 解题思路
内部做了个递归, 判断键值是否为对象, 是则将键值作为root进行递归
记录 60ms, 33.8MB

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
 * @return {number[]}
 */
var preorderTraversal = function(root) {
    
    if(root === null) return [];
    let result = []
    function roots(root) {
        if(!root) return [];
        Object.keys(root).forEach(k => {
            if(typeof root[k] === 'object') {
                roots(root[k])
            } else {
                result.push(root[k])
            }
        })
        return result
    }
    roots(root)
    return result
};
```