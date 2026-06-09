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
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if(!root)return[];
    function dfs(lv, node, map){
        if(!map.has(lv))map.set(lv, []);
        map.get(lv).push(node.val);
        
        const [ln, rn] = [node.left, node.right];
        if(ln)dfs(lv+1, ln, map);
        if(rn)dfs(lv+1, rn, map);
    }
    const collector = new Map();
    dfs(1, root, collector);
    return [...collector.values()];
};
```