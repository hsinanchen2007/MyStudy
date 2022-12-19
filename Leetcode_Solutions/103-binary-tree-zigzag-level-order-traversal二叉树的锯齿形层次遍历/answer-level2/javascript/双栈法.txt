```
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
var zigzagLevelOrder = function(root) {
    if(!root) return [];
    var res = [];
    var l2r = [];
    var r2l = [];
    l2r.push(root);
    while(l2r.length!= 0 || r2l.length!=0) {
        var temp = [];
        if(l2r.length!=0) {
            while(l2r.length!=0) {
                var cur = l2r.pop();
                temp.push(cur.val);
                if(cur.left!=null) r2l.push(cur.left);
                if(cur.right!=null) r2l.push(cur.right);
            }
        }
        else if(r2l.length!=0) {
            while(r2l.length!=0) {
                var cur = r2l.pop();
                temp.push(cur.val);
                if(cur.right!=null) l2r.push(cur.right);
                if(cur.left!=null) l2r.push(cur.left);
            }
        }
        res.push(temp);
    }
    return res;
};
```
