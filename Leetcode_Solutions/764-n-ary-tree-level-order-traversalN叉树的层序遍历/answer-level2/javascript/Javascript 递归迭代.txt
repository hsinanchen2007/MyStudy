
```
/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */
/**
 * @param {Node} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    var result = [];
    var k = 0;
    if (root) {
        dfs(root, result, k)    
    }
    return result;
};

function dfs (cur, result, level) {
    if (cur == null) {
        return 
    }

    for (var i = 0; i < cur.children.length; i ++) {
        if (cur.children.length) {
            dfs(cur.children[i], result, level + 1);
        }
    }

    result[level] ? result[level].push(cur.val) : result[level] = [cur.val]
}
```