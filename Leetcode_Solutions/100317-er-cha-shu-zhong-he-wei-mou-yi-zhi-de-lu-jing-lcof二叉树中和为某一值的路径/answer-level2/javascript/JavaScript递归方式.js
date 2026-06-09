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
var pathSum = function(root, sum) {
    this.res = [];
    this.item = [];
    dfs(root, sum);
    return res;
};

var dfs = function(node, sum){
    if(!node) return;
    if(sum - node.val == 0 && !node.left && !node.right) {
        this.item.push(node.val);
        this.res.push([...item]);
        this.item.pop();
        return;
    }
    this.item.push(node.val);
    dfs(node.left, sum - node.val);
    dfs(node.right, sum - node.val);
    this.item.pop();
}
```