### 解题思路
广度优先遍历，利用一个队列每次遍历左右孩子，如果左孩子是叶子节点就累加

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
var sumOfLeftLeaves = function(root) {
    if(root === null) return 0
    const queue = [];
    let ret = 0;
    queue.push(root.left,root.right)
    while(queue.length>0){
        const left = queue.shift(),
            right = queue.shift();
        if(left){
            if(!left.left && !left.right){
                ret += left.val
            }
            queue.push(left.left,left.right)
        }
        if(right){
            queue.push(right.left,right.right)
        }
    }
    return ret
};
```