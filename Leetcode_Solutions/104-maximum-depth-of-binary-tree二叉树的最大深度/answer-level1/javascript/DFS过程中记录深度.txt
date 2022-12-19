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
var maxDepth = function(root) {
    if(!root)return 0;
    let d=0;
    function dfs(node, c){
        d=Math.max(d,c); //如果当前深度大于历史记录深度，就用新的深度覆盖掉历史记录
        const [l,r]=[node.left, node.right];
        if(l)dfs(l, c+1); //继续进入下层
        if(r)dfs(r, c+1);
    }
    dfs(root, 1);
    return d;
};
```