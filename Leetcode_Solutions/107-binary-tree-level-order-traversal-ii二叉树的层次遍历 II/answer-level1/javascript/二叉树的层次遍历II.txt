1、 BFS 
每一次把顶层取出来，放在level里面，并且下一层的元素全部入列。
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
var levelOrderBottom = function(root) {
    if(root === null) return [];
    let result = [];
    let queue = [];
    queue.push(root);
    while(queue.length) {
        let len = queue.length;
        let level = [];
        while(len--) {
            let node = queue.shift();
            level.push(node.val);
            if(node.left) queue.push(node.left);
            if(node.right) queue.push(node.right);
        }
        result.unshift(level);
    }
    return result;
};
```
时间复杂度：O(n)。
空间复杂度：O(n)。

1、 DFS
深度优先遍历，使用map存每一层的值,最后需要做一个反转，因为是从下往上
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
var levelOrderBottom = function(root) {
    if(!root)return []; 
    function dfs(node,level,map) {
        if(!map.has(level)) map.set(level,[]);
        map.get(level).push(node.val);
        const { left,right } = node;
        if(left) dfs(left,level+1,map); // 注意这里不能使用level++，会改变level的值
        if(right) dfs(right,level+1,map); 
    }
    let map = new Map();
    dfs(root,0,map);
    return [...map.values()].reverse();  
};
```
时间复杂度：O(n)。
空间复杂度：O(n)。