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
    if(root === null) return [];
    var res = [];
    var res_ = [];
    var que = [];
    var chque = [];
    que.push(root);
    while(que.length !== 0){
        let tmp = que.shift();
        res_.push(tmp.val);
        if(tmp.left !== null) chque.push(tmp.left);
        if(tmp.right !== null) chque.push(tmp.right);
        if(que.length === 0){
            que = chque;
            chque = [];
            res.push(res_);
            res_ = [];
        }
    }
    return res;
};
```