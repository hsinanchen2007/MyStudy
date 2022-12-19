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
 * @param {number} val
 * @return {TreeNode}
 */
var searchBST = function(root, val) {
    function find(node){
        if(!node)return null;
        if(val==node.val)return node;
        const [l, r] = [node.left, node.right];
        return find(l) || find(r);
    }
    return find(root);
};
```