### 解题思路
- 二叉树的中序遍历就是从小到大的递增的顺序
- DFS：深度搜索，如果当前状态不符合回到上一步的状态。

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
 * @param {number} k
 * @return {number}
 */
var kthLargest = function(root, k) {
    let arr = [];

    const dfs = (root) =>{
        if(root.left){
            dfs(root.left)
        }
        arr.push(root.val)
        if(root.right){
            dfs(root.right)
        }
    }
    dfs(root)

    return arr.reverse()[k-1];

};
```