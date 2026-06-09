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
var findTilt = function(root) {
    if(!root)return 0;
    return Math.abs(dfs(root.left)-dfs(root.right))+findTilt(root.left)+findTilt(root.right);

    function dfs(root){
        if(!root)return 0;
        return root.val + dfs(root.left)+dfs(root.right);
    }
};
```
方法二：
```
var findTilt = function(root) {
    if(!root)return 0;
    return findTilt(root.left)+findTilt(root.right)+rootTilt(root);
};
//根节点的坡度
function rootTilt(root){
    if(!root)return 0;
    //节点的坡度 = abs(左子树节点的和-右子树节点的和)
    return Math.abs(sum(root.left)-sum(root.right))
}
//树节点的和
function sum(root){
    if(!root)return 0;
    return root.val+sum(root.left)+sum(root.right);
}

```
