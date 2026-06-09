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
 * @param {number} k
 * @return {number}
 */
var kthLargest = function(root, k) {

    let res = [];
    let getTreeSeq = function(root){
    if(root==null)return null;
    getTreeSeq(root.left);
    res.push(root.val);
    getTreeSeq(root.right);

}
getTreeSeq(root);
return res[res.length-k];
    


};

```
终须递归遍历存入res数组
