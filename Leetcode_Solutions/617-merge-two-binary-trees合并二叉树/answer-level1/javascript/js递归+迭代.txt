迭代
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} t1
 * @param {TreeNode} t2
 * @return {TreeNode}
 */

var mergeTrees = function(t1, t2) {
    if(!t1) {
        return t2;
    }
    let arr = [];
    arr.push([t1, t2]);
    while(arr.length !== 0) {
        let temp = arr.pop();
        if(!temp[0] || !temp[1]) {
            continue;
        }
        temp[0].val += temp[1].val;
        if(!temp[0].left) {
            temp[0].left = temp[1].left;
        } else {
            arr.push([temp[0].left, temp[1].left]);
        }
        if(!temp[0].right) {
            temp[0].right = temp[1].right;
        } else {
            arr.push([temp[0].right, temp[1].right]);
        }
    }
    return t1;
};
```
递归
```js
var mergeTrees = function(t1, t2) {
    if(!t1) {
            return t2;
        }
        if(!t2) {
            return t1;
        }
        t1.val += t2.val;
        t1.left = mergeTrees(t1.left, t2.left);
        t1.right = mergeTrees(t1.right, t2.right);
        return t1;
}
```