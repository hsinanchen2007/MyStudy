```
//node结构
node = {
    val: 1,
    right:
        {
            val: 2,
            right: null,
            left: { val: 3, right: null, left: null }
        },
    left: null
}
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
    var ret = [];
    if(!root) return [];

    ret.push(root.val);
    var l = root.left,
        r = root.right;
    return ret.concat(arguments.callee(l)).concat(arguments.callee(r))
};
```


